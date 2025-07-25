/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:23:00 by suju              #+#    #+#             */
/*   Updated: 2025/07/25 17:15:37 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	strarr_to_intarr(char *str_arr[], int int_arr[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		int_arr[i] = ft_atoi(str_arr[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		*int_arr[];

	if (argc >= 2)
	{
		if (aggc == 2)
		{
			ft_isdigit()
			ft_split(argv[1], ' ');
		}
		else
		{

		}
	}
	else
	{
		
	}
	ft_printf("Error");
	ft_printf("\n");
	return (0);
}
