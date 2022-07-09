/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:52:28 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/09 16:55:36 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_times(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (-b);
}

int	put_a_few_times(t_stack *a, int b)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (++i <= a->top)
		if (a->st[i] > a->st[i - 1])
			max = i;
	if (max == 0 && (b < a->st[a->top] || b > a->st[0]))
		return (0);
	if (max != 0 && (b < a->st[max - 1] || b > a->st[max]))
		return (min_times(a->top - max + 1, max));
	i = 0;
	while (++i <= a->top)
	{
		if (b < a->st[i - 1] && b > a->st[i])
			return (min_times(a->top - i + 1, i));
	}
	if (b < a->st[a->top] && b > a->st[0])
		return (0);
	write(2, "Error2\n", 7);
	return (10000);
}

int	a_few_times(int a, int b)
{
	if (a > 0 && b > 0)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else if (a < 0 && b < 0)
	{
		if (a > b)
			return (-b);
		else
			return (-a);
	}
	else if (a < 0)
		return (b - a);
	else if (b < 0)
		return (a - b);
	return (a + b);
}

void	optimal_times(int *b_ts, int *a_ts, int a_top, int b_top)
{
	if ((*b_ts) < 0)
	{
		if (a_few_times((*a_ts), (b_top + 1) + (*b_ts))
			< a_few_times((*b_ts), -((a_top + 1) - (*a_ts))))
		{
			if ((*a_ts) - (*b_ts) > a_few_times((*a_ts), (b_top + 1) + (*b_ts)))
				(*b_ts) = (b_top + 1) + (*b_ts);
		}
		else if ((*a_ts) -(*b_ts) > a_few_times((*b_ts), -(a_top + 1 -(*a_ts))))
			(*a_ts) = -((a_top + 1) - (*a_ts));
	}
	else
	{
		if (a_few_times((*a_ts), -((b_top + 1) - (*b_ts)))
			< a_few_times((*b_ts), (a_top + 1) + (*a_ts)))
		{
			if ((*b_ts) -(*a_ts) > a_few_times((*a_ts), -(b_top + 1 + (*b_ts))))
				(*b_ts) = -((b_top + 1) - (*b_ts));
		}
		else if ((*b_ts) - (*a_ts)
			> a_few_times((*b_ts), (a_top + 1) + (*a_ts)))
			(*a_ts) = (a_top + 1) + (*a_ts);
	}
}

void	min_to_the_top(t_stack *a)
{
	int	min;
	int	i;

	i = 0;
	min = 0;
	while (++i <= a->top)
		if (a->st[i] < a->st[min])
			min = i;
	if (min >= (a->top / 2))
		while (++min <= a->top)
			ra(a);
	else
		while (--min >= -1)
			rra(a);
}
