/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:06:23 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/09 17:01:45 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack *a);
static void	sort_5(t_stack *a, t_stack *b);
static void	sorting(t_stack *a, t_stack *b);

static void	sort_3(t_stack *a)
{
	int	i;
	int	j;
	int	k;

	i = a->st[2];
	j = a->st[1];
	k = a->st[0];
	if ((i < j && j < k && i < k)
		|| (i < j && j > k && i > k)
		|| (i > j && i > k && j < k))
		return ;
	else if ((i > j && j < k && i < k)
		|| (i > j && j > k && i > k))
		sa(a);
	else if (i < j && j > k && i < k)
	{
		ra(a);
		sa(a);
	}
}

static void	sort_5(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	sort_3(a);
	while (b->top != -1)
		sorting(a, b);
}

static void	sorting(t_stack *a, t_stack *b)
{
	int	check_list[ST_SIZE][3];
	int	min_stack;
	int	i;

	i = -1;
	min_stack = 0;
	while (++i <= b->top)
	{
		check_list[i][0] = min_times(b->top - i, i + 1);
		check_list[i][1] = put_a_few_times(a, b->st[i]);
		if (check_list[i][0] * check_list[i][1] < 0)
			optimal_times(&check_list[i][0], &check_list[i][1], a->top, b->top);
		check_list[i][2] = a_few_times(check_list[i][0], check_list[i][1]);
		if (check_list[i][2] < check_list[min_stack][2])
			min_stack = i;
	}
	if (check_list[min_stack][0] > 0 && check_list[min_stack][1] > 0)
		both_r(a, b, check_list[min_stack][1], check_list[min_stack][0]);
	else if (check_list[min_stack][0] < 0 && check_list[min_stack][1] < 0)
		both_rr(a, b, check_list[min_stack][1], check_list[min_stack][0]);
	else
		sep_move(a, b, check_list[min_stack][1], check_list[min_stack][0]);
	pa(a, b);
}

void	stack_sort(t_stack *a, t_stack *b)
{
	int	amount;
	int	lis[ST_SIZE + 1];

	if (a->top == 2)
		sort_3(a);
	else if (a->top == 4)
		sort_5(a, b);
	else
	{
		lis_sort(a, lis, 0);
		amount = a->top;
		separate_stack(a, b, lis);
		while (amount != a->top)
			sorting(a, b);
	}
	min_to_the_top(a);
}
