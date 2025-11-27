/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:44:12 by suju              #+#    #+#             */
/*   Updated: 2025/08/11 14:44:15 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_pipex.h"

void    execute_cmd(char *cmd_str, char *envp[])
{
    char    **cmd_argv;
    char    *cmd_name;

	cmd_argv = ft_split(cmd_str, ' ');
    if (!cmd_argv || !cmd_argv[0])
    {
        free_ptr_arr(cmd_argv);
        // TODO: 에러 처리;
    }
    cmd_name = find_cmd_path(cmd_argv[0], envp);
    if (!cmd_name || access(cmd_name, X_OK) == -1)
    {
        free_ptr_arr(cmd_argv);
        if (!cmd_name)
            error_exit("command not found", 127);
        error_exit("permission denied", 126);
    }
    if (execve(cmd_name, cmd_argv, envp) == -1)
    {
        free_ptr_arr(cmd_argv);
        free(cmd_name);
        error_exit("execve", EXIT_FAILURE);
    }
}

void    child_process(char* argv[], char *envp[], int cmd_cnt, int cmd_idx, int **pipes)
{
    int is_here_doc;

    is_here_doc = is_here_doc_mode(argv[1]);
    setup_io_redirection(cmd_cnt, cmd_idx, pipes);
    if (cmd_idx == 0)
        setup_input_redirection(argv, is_here_doc);
    if (cmd_idx == cmd_cnt - 1)
        setup_output_redirection(argv, is_here_doc);
    // close_pipes()? TODO: 왜 파이프를 다 닫아야 하지? 이 함수는 자식 프로세스 하나당 1번씩 작동하는데?
    if (is_here_doc)
        execute_cmd(argv[cmd_idx + 3], envp);
    else
        execute_cmd(argv[cmd_idx + 2], envp);
}

void    wait_child_processes(pid_t *pids, int child_processes_cnt)
{
    int i;
    int status;

    i = 0;
    while (i < child_processes_cnt)
    {
        waitpid(pids[i], &status, 0);
        i++;
    }
    if (WIFEXITED(status))
        exit(WEXITSTATUS(status));
}

int     main(int argc, char *argv[], char *envp[])
{
	int		**pipes;
    int     cmd_cnt;
    int     i;
	pid_t	*pids;

	validate_args_bonus(argc);
    cmd_cnt = get_cmd_count(argc, argv);
    pipes = create_pipes(cmd_cnt - 1);
    if (!pipes)
        error_exit(); // TODO: error 핸들링 필요
    pids = (pid_t)malloc(sizeof(pid_t) * cmd_cnt);
    if (!pids)
        error_exit(); // TODO: error 핸들링 필요
    i = 0;
    while (i < cmd_cnt)
    {
        pids[i] = fork();
        if (pids[i] == -1)
            error_exit(); // TODO: error 핸들링 필요
        if (pids[i] == 0)
            child_process(argv, envp, cmd_cnt, i, pipes);
        i++;
    }
    close_pipes(pipes, cmd_cnt - 1);
    wait_child_processes(pids, cmd_cnt);
    free_resources();
	return (EXIT_SUCCESS);
}

