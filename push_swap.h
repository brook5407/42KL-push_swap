/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchin <chchin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:52:37 by chchin            #+#    #+#             */
/*   Updated: 2022/07/27 12:07:39 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// data - store integer type variable value inside every node 链表数据
// prev - connect to previous node 指向上一个链表指针
// next - connect to next node 指向下一个链表指针
typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

// int	size - the total size of linked list 链表的长度
// t_node	top  - connect to first position of linked list 指向第一个链表指针
// t_node	btm  - connect to last position of linked list 指向最后一个链表指针
typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*btm;
}			t_stack;

void	set_null_stack(t_stack *stack);
void	exit_error(void);
void	ft_free_list(t_stack *stack);
void	ft_free_all(t_stack *a, t_stack *b);

int		correct_order(t_stack *a);
int		correct_order_b(t_stack *b);

t_stack	*init_stack(void);
t_node	*create_stack(int argc, char **argv, t_stack **stack);

void	check_duplicate(t_node *a);
int		ft_atoi_check(const char *str);

void	swap_stack_a(t_stack *stack_a);
void	swap_stack_b(t_stack *stack_b);
void	swap_stack_all(t_stack *stack_a, t_stack *stack_b);

void	push_top_a_to_b(t_stack *stack_a, t_stack *stack_b);
void	push_top_b_to_a(t_stack *stack_b, t_stack *stack_a);

void	rotate_stack_a(t_stack *stack_a);
void	rotate_stack_b(t_stack *stack_b);
void	rotate_stack_all(t_stack *stack_a, t_stack *stack_b);

void	rev_rotate_stack_a(t_stack *stack_a);
void	rev_rotate_stack_b(t_stack *stack_b);
void	rev_rotate_stack_all(t_stack *stack_a, t_stack *stack_b);

int		ft_find_max(const t_node *node, int size);
int		ft_find_min(const t_node *node, int size);
int		ft_find_sec_min(const t_node *node, int size);
int		ft_find_pos(t_node *node, int value);
int		ft_steps(t_node *node, int value, int size);

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_under_100(t_stack *a, t_stack *b);
void	sort_big_stack(t_stack *stack_a, t_stack *stack_b);

#endif
