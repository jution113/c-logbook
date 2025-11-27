/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:12:05 by suju              #+#    #+#             */
/*   Updated: 2025/11/27 11:31:25 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * 비용(A회전, B회전 횟수)을 계산하는 헬퍼
 */
static void	get_move_costs(t_stack *a, t_stack *b, t_node *node)
{
	node->cost_b = node->index;
	if (node->index > b->size / 2)
		node->cost_b = (b->size - node->index) * -1;
	node->cost_a = node->target->index;
	if (node->target->index > a->size / 2)
		node->cost_a = (a->size - node->target->index) * -1;
	if ((node->cost_a > 0 && node->cost_b > 0)
		|| (node->cost_a < 0 && node->cost_b < 0))
	{
		if (ft_abs(node->cost_a) > ft_abs(node->cost_b))
			node->push_cost = ft_abs(node->cost_a);
		else
			node->push_cost = ft_abs(node->cost_b);
	}
	else
		node->push_cost = ft_abs(node->cost_a) + ft_abs(node->cost_b);
}

/*
 * 스택 B를 순회하며 비용을 계산하고 가장 저렴한 노드를 찾는 함수
 */
static t_node	*get_cheapest_node(t_stack *a, t_stack *b)
{
	t_node	*cur_node;
	t_node	*cheapest_node;
	long	min_cost;

	cur_node = b->top;
	cheapest_node = NULL;
	min_cost = LONG_MAX;
	while (cur_node)
	{
		get_move_costs(a, b, cur_node);
		if (cur_node->push_cost < min_cost)
		{
			min_cost = cur_node->push_cost;
			cheapest_node = cur_node;
		}
		cur_node = cur_node->next;
	}
	return (cheapest_node);
}

static void	do_both_rotate(t_stack *a, t_stack *b, t_node *node)
{
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		rr(a, b);
		node->cost_a--;
		node->cost_b--;
	}
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		rrr(a, b);
		node->cost_a++;
		node->cost_b++;
	}
}

static void	do_single_rotate(t_stack *a, t_stack *b, t_node *node)
{
	while (node->cost_a > 0)
	{
		ra(a);
		node->cost_a--;
	}
	while (node->cost_a < 0)
	{
		rra(a);
		node->cost_a++;
	}
	while (node->cost_b > 0)
	{
		rb(b);
		node->cost_b--;
	}
	while (node->cost_b < 0)
	{
		rrb(b);
		node->cost_b++;
	}
	pa(a, b);
}

/*
 * 메인 함수: 인덱스 갱신 -> 타겟 설정 -> 최적노드 찾기 -> 이동 실행
 */
void	do_cheapest_move(t_stack *a, t_stack *b)
{
	t_node	*cheapest_node;

	update_index(a);
	update_index(b);
	set_target_position(a, b);
	cheapest_node = get_cheapest_node(a, b);
	if (!cheapest_node)
		return ;
	get_move_costs(a, b, cheapest_node);
	do_both_rotate(a, b, cheapest_node);
	do_single_rotate(a, b, cheapest_node);
}
