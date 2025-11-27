/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:12:00 by suju              #+#    #+#             */
/*   Updated: 2025/11/26 16:01:06 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	update_index(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->top;
	while (node)
	{
		node->index = i;
		node = node->next;
		i++;
	}
}

t_node	*find_min_node(t_stack *stack)
{
	t_node	*min_node;
	t_node	*cur_node;

	if (!stack || !stack->top)
		return (NULL);
	min_node = stack->top;
	cur_node = stack->top->next;
	while (cur_node)
	{
		if (cur_node->value < min_node->value)
			min_node = cur_node;
		cur_node = cur_node->next;
	}
	return (min_node);
}

t_node	*find_max_node(t_stack *stack)
{
	t_node	*max_node;
	t_node	*cur_node;

	if (!stack || !stack->top)
		return (NULL);
	max_node = stack->top;
	cur_node = stack->top->next;
	while (cur_node)
	{
		if (cur_node->value > max_node->value)
			max_node = cur_node;
		cur_node = cur_node->next;
	}
	return (max_node);
}

/*
 * B의 각 노드가 A의 어디로 들어가야 하는지 결정 (타겟 설정)
 * 타겟 조건: B값보다 큰 값들 중 가장 작은 값 (없으면 A의 최소값이 타겟)
 */
void	set_target_position(t_stack *a, t_stack *b)
{
	t_node	*cur_b;
	t_node	*cur_a;
	t_node	*target;
	long	best_match_val;

	cur_b = b->top;
	while (cur_b)
	{
		best_match_val = LONG_MAX;
		cur_a = a->top;
		while (cur_a)
		{
			if (cur_a->value > cur_b->value && cur_a->value < best_match_val)
			{
				best_match_val = cur_a->value;
				target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (best_match_val == LONG_MAX)
			cur_b->target = find_min_node(a);
		else
			cur_b->target = target;
		cur_b = cur_b->next;
	}
}
