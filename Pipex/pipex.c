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

#include "./includes/pipex.h"

void	execute_cmd(char *cmd_str, char *envp[])
{
	char	**cmd_argv;
	char	*cmd_name;

	cmd_argv = ft_split(cmd_str, ' ');
	if (!cmd_argv || !cmd_argv[0])
		error_exit("ft_split");
	cmd_name = find_cmd_path(cmd_argv[0], envp);
	if (!cmd_name)
	{
		free_ptr_arr(cmd_argv);
		error_exit("find_cmd_path");
	}
	if (execve(cmd_name, cmd_argv, envp) == -1)
	{
		free_ptr_arr(cmd_argv);
		free(cmd_name);
		error_exit("execve");
	}
}

void	child_process_task(char *argv[], int *pipe_fd, char *envp[])
{
	char	*file_name;
	char	*cmd_str;
	int		opened_fd;

	file_name = argv[1];
	cmd_str = argv[2];
	opened_fd = open(file_name, O_RDONLY);
	if (opened_fd == -1)
		error_exit("open");
	if (close(pipe_fd[0] == -1))
		error_exit("close");
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		error_exit("dup2");
	if (dup2(opened_fd, STDIN_FILENO) == -1)
		error_exit("dup2");
	execute_cmd(cmd_str, envp);
}

void	parent_process_task(char *argv[], int *pipe_fd, char *envp[])
{
	char	*file_name;
	char	*cmd_str;
	int		opened_fd;

	file_name = argv[4];
	cmd_str = argv[3];
	opened_fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC);
	if (opened_fd == -1)
		error_exit("open");
	if (close(pipe_fd[1] == -1))
		error_exit("close");
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		error_exit("dup2");
	if (dup2(opened_fd, STDOUT_FILENO) == -1)
		error_exit("dup2");
	execute_cmd(cmd_str, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pipe_fd[2];
	pid_t	pid;

	if (argc < 5)
	{
		ft_putstr_fd("Error: Invalid number of arguments.\n", 2);
		ft_putstr_fd("Expected: ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipe_fd) == -1)
		error_exit("pipe");
	pid = fork();
	if (pid == -1)
		error_exit("fork");
	if (pid == 0)
		child_process_task(argv, pipe_fd, envp);
	else
	{
		wait(NULL);
		parent_process_task(argv, pipe_fd, envp);
	}
	return (0);
}
