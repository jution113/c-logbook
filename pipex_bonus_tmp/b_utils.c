/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:57:18 by suju              #+#    #+#             */
/*   Updated: 2025/08/11 14:57:19 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_pipex.h"

void	validate_args_bonus(int argc)
{
	if (argc < 5)
	{
		ft_putstr_fd("[Error] Expected: ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(EXIT_FAILURE);
	}
}

int		is_here_doc_mode(char *arg)
{
	return (ft_strncmp(arg, "here_doc", 8) == 0);
}

int		get_cmd_count(int argc, char *argv[])
{
    if (is_here_doc_mode(argv[1]))
        return (argc - 4);
    return (argc - 3);
}
