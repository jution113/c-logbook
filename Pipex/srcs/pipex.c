/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:00:00 by suju              #+#    #+#             */
/*   Updated: 2025/08/08 14:33:36 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	execute_cmd(char *cmd_str, char *envp[])
{
	char	**cmd_argv;
	char	*cmd_name;

	cmd_argv = ft_split(cmd_str, ' ');
	if (!cmd_argv || !cmd_argv[0])
	{
		free_ptr_arr(cmd_argv);
		error_exit("ft_split", EXIT_FAILURE);
	}
	cmd_name = find_cmd_path(cmd_argv[0], envp);
	if (!cmd_name || access(cmd_name, X_OK) == -1)
	{
		free_ptr_arr(cmd_argv);
		if (!cmd_name)
			error_exit("command not found", 127);
		free(cmd_name);
		error_exit("permission denied", 126);
	}
	if (execve(cmd_name, cmd_argv, envp) == -1)
	{
		free_ptr_arr(cmd_argv);
		free(cmd_name);
		error_exit("execve", EXIT_FAILURE);
	}
}

void	first_child_process(char *argv[], int *pipe_fd, char *envp[])
{
	char	*file_name;
	char	*cmd_str;
	int		opened_fd;

	file_name = argv[1];
	cmd_str = argv[2];
	if (close(pipe_fd[0]) == -1)
		error_exit("close", EXIT_FAILURE);
	opened_fd = open(file_name, O_RDONLY, 0777);
	if (opened_fd == -1)
		error_exit("open", EXIT_FAILURE);
	if (dup2(opened_fd, 0) == -1 || dup2(pipe_fd[1], 1) == -1)
		error_exit("dup2", EXIT_FAILURE);
	if (close(pipe_fd[1]) == -1 || close(opened_fd) == -1)
		error_exit("close", EXIT_FAILURE);
	execute_cmd(cmd_str, envp);
}

void	second_child_process(char *argv[], int *pipe_fd, char *envp[])
{
	char	*file_name;
	char	*cmd_str;
	int		opened_fd;

	file_name = argv[4];
	cmd_str = argv[3];
	if (close(pipe_fd[1]) == -1)
		error_exit("close", 1);
	opened_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (opened_fd == -1)
		error_exit("open", EXIT_FAILURE);
	if (dup2(opened_fd, 1) == -1 || dup2(pipe_fd[0], 0) == -1)
		error_exit("dup2", EXIT_FAILURE);
	if (close(pipe_fd[0]) == -1 || close(opened_fd) == -1)
		error_exit("close", EXIT_FAILURE);
	execute_cmd(cmd_str, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pipe_fd[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	validate_args(argc);
	if (pipe(pipe_fd) == -1)
		error_exit("pipe", EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		error_exit("fork", EXIT_FAILURE);
	if (pid1 == 0)
		first_child_process(argv, pipe_fd, envp);
	pid2 = fork();
	if (pid2 == -1)
		error_exit("fork", EXIT_FAILURE);
	if (pid2 == 0)
		second_child_process(argv, pipe_fd, envp);
	if (close(pipe_fd[0]) == -1 || close(pipe_fd[1]) == -1)
		error_exit("close", EXIT_FAILURE);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
