/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:00:39 by suju              #+#    #+#             */
/*   Updated: 2025/11/25 16:46:17 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
	int				index;
	int				value;
	int				push_cost;
	int				cost_a;
	int				cost_b;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

/* Main */
void	error_exit(t_stack *a, t_stack *b, int error_code);

/* Operations */
void	push(t_stack *src, t_stack *dst);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	swap(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	rotate(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* Stack Utils */
void	init_stack(t_stack *stack);
void	add_node(int value, t_stack *a, t_stack *b);
void	free_stack(t_stack *stack);
void	free_all_stack(t_stack *a, t_stack *b);

/* Parsing */
void	parse_args(int argc, char **argv, t_stack *a, t_stack *b);

/* Parsing Util*/
int		ft_isdigit(int c);
int		ft_isspace(char c);
int		check_is_number(char *str);
long	ft_atol(const char *str);

/* Sort Utils */
int		ft_abs(int n);
int		is_sorted(t_stack *stack);
void	update_index(t_stack *stack);
void	set_target_position(t_stack *a, t_stack *b);
t_node	*find_min_node(t_stack *stack);
t_node	*find_max_node(t_stack *stack);

/* Sort Algorithm */
void	sort_three(t_stack *a);
void	sort_stack(t_stack *a, t_stack *b);
void	do_cheapest_move(t_stack *a, t_stack *b);
#endif
