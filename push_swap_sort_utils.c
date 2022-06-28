/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:52:28 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/28 20:51:59 by yichoi           ###   ########.fr       */
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
	i = 0;
	if (max == 0 && (b < a->st[a->top] || b > a->st[0]))
		return (0);
	if (max != 0 && (b < a->st[max - 1] || b > a->st[max]))
		;
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
