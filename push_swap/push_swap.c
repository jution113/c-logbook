/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:09:45 by suju              #+#    #+#             */
/*   Updated: 2025/11/25 16:13:13 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *a, t_stack *b, int error_code)
{
	if (error_code == 1)
		free_stack(a);
	else if (error_code == 2)
		free_all_stack(a, b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	select_algorithm(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size > 3)
		sort_stack(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = malloc(sizeof(t_stack));
	if (!a)
		error_exit(NULL, NULL, 0);
	init_stack(a);
	b = malloc(sizeof(t_stack));
	if (!b)
		error_exit(a, NULL, 1);
	init_stack(b);
	parse_args(argc, argv, a, b);
	if (!is_sorted(a))
		select_algorithm(a, b);
	free_all_stack(a, b);
	return (0);
}
