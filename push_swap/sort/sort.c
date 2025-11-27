/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:12:11 by suju              #+#    #+#             */
/*   Updated: 2025/11/26 19:56:02 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*cur_node;

	if (!stack ||!stack->top)
		return (1);
	cur_node = stack->top;
	while (cur_node->next)
	{
		if (cur_node->value > cur_node->next->value)
			return (0);
		cur_node = cur_node->next;
	}
	return (1);
}

void	sort_three(t_stack *a)
{
	int	max;

	max = find_max_node(a)->value;
	if (a->top->value == max)
		ra(a);
	else if (a->top->next->value == max)
		rra(a);
	if (a->top->value > a->top->next->value)
		sa(a);
}

/*
1. A에 3개 남을 때까지 B로 넘김
2. 남은 3개 정렬
3. B에서 A로 최적의 노드를 하나씩 이동
4. 최종 정렬: A의 최소값이 맨 위로 오도록 회전
*/
void	sort_stack(t_stack *a, t_stack *b)
{
	int		index;
	t_node	*min_node;

	while (a->size > 3)
		pb(a, b);
	sort_three(a);
	while (b->size > 0)
	{
		do_cheapest_move(a, b);
	}
	min_node = find_min_node(a);
	update_index(a);
	index = min_node->index;
	if (index <= a->size / 2)
		while (a->top != min_node)
			ra(a);
	else
		while (a->top != min_node)
			rra(a);
}
