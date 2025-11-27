/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:17:03 by suju              #+#    #+#             */
/*   Updated: 2025/11/25 16:50:27 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->push_cost = 0;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->target = NULL;
	return (new_node);
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	add_node(int value, t_stack *a, t_stack *b)
{
	t_node	*cur_node;
	t_node	*new_node;

	cur_node = a->top;
	while (cur_node)
	{
		if (cur_node->value == value)
			error_exit(a, b, 2);
		cur_node = cur_node->next;
	}
	new_node = create_node(value);
	if (!new_node)
		error_exit(a, b, 2);
	if (a->size == 0)
	{
		a->top = new_node;
		a->bottom = new_node;
	}
	else
	{
		a->bottom->next = new_node;
		new_node->prev = a->bottom;
		a->bottom = new_node;
	}
	a->size++;
}

void	free_stack(t_stack *stack)
{
	t_node	*cur_node;
	t_node	*temp;

	if (!stack)
		return ;
	cur_node = stack->top;
	while (cur_node)
	{
		temp = cur_node->next;
		free(cur_node);
		cur_node = temp;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	free(stack);
}

void	free_all_stack(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}
