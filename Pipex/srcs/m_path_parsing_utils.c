/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:51:09 by suju              #+#    #+#             */
/*   Updated: 2025/08/10 20:51:11 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/m_pipex.h"

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
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

int	is_path_command(char *cmd_name)
{
	int	is_absolute;
	int	is_current_relative;
	int	is_parent_relative;

	is_absolute = 0;
	is_current_relative = 0;
	is_parent_relative = 0;
	if (cmd_name[0] == '/')
		is_absolute = 1;
	else if (cmd_name[0] == '.')
	{
		if (cmd_name[1] == '/')
			is_current_relative = 1;
		else if (cmd_name[1] == '.' && cmd_name[2] == '/')
			is_parent_relative = 1;
	}
	return (is_absolute || is_current_relative || is_parent_relative);
}

char	*find_cmd_path(char *cmd_name, char *envp[])
{
	char	**cmd_path_arr;
	char	*cmd_path;
	int		i;

	if (is_path_command(cmd_name))
	{
		if (access(cmd_name, F_OK) == 0)
			return (cmd_name);
		return (NULL);
	}
	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH", 4))
		i++;
	cmd_path_arr = ft_split(envp[i] + 5, ':');
	if (!cmd_path_arr)
		return (NULL);
	cmd_path = find_executable_path(cmd_name, cmd_path_arr);
	free_ptr_arr(cmd_path_arr);
	return (cmd_path);
}
