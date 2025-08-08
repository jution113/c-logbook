/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:00:30 by suju              #+#    #+#             */
/*   Updated: 2025/08/07 16:00:33 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	error_exit(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	free_ptr_arr(char **ptr_arr)
{
	while (*ptr_arr)
	{
		free(*ptr_arr);
		ptr_arr++;
	}
	free(ptr_arr);
}

char	*find_executable_path(char *cmd_name, char **cmd_path_arr)
{
	char	*cmd_path;
	char	*tmp;
	int		i;

	i = 0;
	while (cmd_path_arr[i])
	{
		tmp = ft_strjoin(cmd_path_arr[i], "/");
		if (!tmp)
			return (NULL);
		cmd_path = ft_strjoin(tmp, cmd_name);
		free(tmp);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(char *cmd_name, char *envp[])
{
	char	**cmd_path_arr;
	char	*cmd_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	cmd_path_arr = ft_split(envp[i] + 5, ':');
	if (!cmd_path_arr)
		error_exit("ft_split");
	cmd_path = find_executable_path(cmd_name, cmd_path_arr);
	free_ptr_arr(cmd_path_arr);
	if (!cmd_path)
		error_exit("find_executable_path");
	return (cmd_path);
}
