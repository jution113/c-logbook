/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:53:20 by suju              #+#    #+#             */
/*   Updated: 2025/08/06 16:53:16 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	execute_cmd()
{

}


void	execute_cmd1(char *pathname, char *cmd1, int *pipe_fd)
{
	int	opened_fd;
		
	opened_fd = open(pathname, O_RDONLY);
	if (fd == -1)
		error_exit("open");
	close(pipe_fd[0]);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		error_exit("dup2");
	if (dup2(opened_fd, STDIN_FILENO) == -1)
		error_exti("dup2");
	execute_cmd(cmd1);
}

void	execute_cmd2()
{

}

int		main(int argc, char *argv[])
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
		execute_cmd1(argv[1], argv[2], pipe_fd);
	else
		execute_cmd2();
	return (0);
}
