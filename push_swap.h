/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:00:37 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/09 16:51:56 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# define ST_SIZE 1000

typedef struct s_stack
{
	int	top;
	int	st[ST_SIZE];
}	t_stack;

void	check_integer(char *str);
void	check_dup(t_stack *a);

void	ft_error(void);
void	split_free(char **str);
void	start_stack(t_stack *start1, t_stack *start2);
int		push_swap_atoi(const char *str);

void	str_enqueue(t_stack *a, char *argv[]);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	swap(t_stack *sw);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *s, int reverse);

void	stack_sort(t_stack *a, t_stack *b);

int		min_times(int a, int b);
int		put_a_few_times(t_stack *a, int b);
int		a_few_times(int a, int b);
void	optimal_times(int *b_ts, int *a_ts, int a_top, int b_top);
void	min_to_the_top(t_stack *a);

void	both_r(t_stack *a, t_stack *b, int a_ts, int b_ts);
void	both_rr(t_stack *a, t_stack *b, int a_ts, int b_ts);
void	sep_move(t_stack *a, t_stack *b, int a_ts, int b_ts);
void	separate_stack(t_stack *a, t_stack *b, int *lis);

void	lis_sort(t_stack *a, int *lis, int i);
void	get_lis(t_stack *a, int *result, int size, int *lis);
int		b_search(int *dp, int a, int s, int e);

#endif
