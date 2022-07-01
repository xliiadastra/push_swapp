/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:06:23 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/29 19:56:03 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_stack *a)
{
	int	i;
	int	j;
	int	k;

	i = a->st[a->top];
	j = a->st[a->top - 1];
	k = a->st[a->top - 2];
	if ((i < j && j < k && i < k)
		|| (i < j && j > k && i > k)
		|| (i > j && j < k && i < k))
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
	pb(b, a);
	pb(b, a);
	sort_3(a);
	while (b->top != -1)
		sort(a, b);
}

static void	sort(t_stack *a, t_stack *b)
{
	int	check_list[ST_SIZE][2];
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
		both_rr(a, b, check_list[min_stack][0], check_list[min_stack][1]);
	else if (check_list[min_stack][0] < 0 && check_list[min_stack][1] < 0)
		both_rrr(a, b, check_list[min_stack][0], check_list[min_stack][1]);
	else
}

void	stack_sort(t_stack *a, t_stack *b)
{
	if (a->top = 2)
		sort_3(a);
	else if (a->top = 4)
		sort_5(a);
	else
	{
	}
	min_to_the_top(a);
}
