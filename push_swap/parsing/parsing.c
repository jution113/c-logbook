/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:17:24 by suju              #+#    #+#             */
/*   Updated: 2025/11/26 11:53:08 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_string_mode(char *str, t_stack *a, t_stack *b)
{
	long	value;
	int		i;

	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		if (!str[i])
			break ;
		if (str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i]))
			error_exit(a, b, 2);
		if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
			error_exit(a, b, 2);
		value = ft_atol(&str[i]);
		if (value > INT_MAX || value < INT_MIN)
			error_exit(a, b, 2);
		add_node((int)value, a, b);
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (ft_isdigit(str[i]))
			i++;
	}
}

static void	parse_args_mode(int argc, char **argv, t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	long	value;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (!argv[i][0])
			error_exit(a, b, 2);
		while (argv[i][j])
		{
			if (ft_isspace(argv[i][j]))
				error_exit(a, b, 2);
			j++;
		}
		if (!check_is_number(argv[i]))
			error_exit(a, b, 2);
		value = ft_atol(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			error_exit(a, b, 2);
		add_node((int)value, a, b);
		i++;
	}
}

void	parse_args(int argc, char **argv, t_stack *a, t_stack *b)
{
	if (argc == 2)
	{
		if (!argv[1][0])
			error_exit(a, b, 2);
		parse_string_mode(argv[1], a, b);
	}
	else
	{
		parse_args_mode(argc, argv, a, b);
	}
}
