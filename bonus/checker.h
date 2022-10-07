/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brook <brook@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:36:38 by brook             #+#    #+#             */
/*   Updated: 2022/07/25 21:53:21 by brook            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*btm;
}			t_stack;

t_stack	*init_stack(void);
t_node	*create_stack(int argc, char **argv, t_stack **stack);

void	check_duplicate(t_node *a);
int		ft_atoi_check(const char *str);

void	set_null_stack(t_stack *stack);
void	exit_error(void);
void	ft_free_list(t_stack *stack);
void	ft_free_all(t_stack *a, t_stack *b);

void	push_top(t_stack **from, t_stack **to);
void	rotate_bottom_to_top(t_stack **stack);
void	rotate_top_to_bottom(t_stack **stack);
void	swap_top(t_stack **stack);

void	run_push(char *buf, t_stack *a, t_stack *b);
void	run_swap(char *buf, t_stack *a, t_stack *b);
void	run_rotate(char *buf, t_stack *a, t_stack *b);
void	run_rev_rotate(char *buf, t_stack *a, t_stack *b);

int		correct_order(t_stack *a);
void	checker(t_stack *a, t_stack *b);

#endif
