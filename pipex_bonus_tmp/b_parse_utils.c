/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parse_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:20:23 by suju              #+#    #+#             */
/*   Updated: 2025/08/11 20:20:24 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_pipex.h"

int count_argc(char *str)
{
    int cnt;

    cnt = 0;
    while (1)
    {

    }
    return (cnt);
}

char    **parse_cmd_args(char *cmd_str)
{
    char    **argv;
    int argc;

    if (!cmd_str)
        return (NULL);
    argc = count_argc(cmd_str);
    if (argc == 0)
        return (NULL);
    argv = (char**)malloc(sizeof(char *) * (argc + 1));
    if (!argv)
        return (NULL);
    return(argv);
}
