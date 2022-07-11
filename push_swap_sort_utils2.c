/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:00:37 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/09 17:02:21 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_r(t_stack *a, t_stack *b, int a_ts, int b_ts)
{
	if (a_ts > b_ts)
	{
		while (a_ts-- > b_ts)
			ra(a);
		while (b_ts-- > 0)
			rr(a, b);
	}
	else
	{
		while (a_ts < b_ts--)
			rb(b);
		while (a_ts-- > 0)
			rr(a, b);
	}
}

void	both_rr(t_stack *a, t_stack *b, int a_ts, int b_ts)
{
	if (a_ts > b_ts)
	{
		while (a_ts > b_ts++)
			rrb(b);
		while (a_ts++ < 0)
			rrr(a, b);
	}
	else
	{
		while (a_ts++ < b_ts)
			rra(a);
		while (b_ts++ < 0)
			rrr(a, b);
	}
}

void	sep_move(t_stack *a, t_stack *b, int a_ts, int b_ts)
{
	if (a_ts > 0)
	{
		while (a_ts-- > 0)
			ra(a);
	}
	else
	{
		while (a_ts++ < 0)
			rra(a);
	}
	if (b_ts > 0)
	{
		while (b_ts-- > 0)
			rb(b);
	}
	else
	{
		while (b_ts++ < 0)
			rrb(b);
	}
}

void	separate_stack(t_stack *a, t_stack *b, int *lis)
{
	int	size;
	int	total;
	int	push;

	size = lis[0];
	push = 0;
	total = a->top + 1 - size;
	while (push != total)
	{
		if (size > 0 && a->st[a->top] == lis[size])
		{
			ra(a);
			--size;
		}
		else
		{
			pb(a, b);
			++push;
		}
	}
}
