/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_lis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:30:08 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/05 22:12:03 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis_sort(t_stack *a, int *lis, int i)
{
	int	size;
	int	pos;
	int	dp[ST_SIZE];
	int	result[ST_SIZE];

	size = 0;
	dp[0] = a->st[0];
	result[0] = 0;
	while (++i <= a->top)
	{
		if (dp[size] > a->st[i])
		{
			dp[++size] = a->st[i];
			pos = size;
		}
		else
		{
			pos = b_search(dp, a->st[i], 0, size);
			if (pos != -1 && pos <= size)
				dp[pos] = a->st[i];
		}
		result[i] = pos;
	}
	get_lis(a, result, size, lis);
}

void	get_lis(t_stack *a, int *result, int size, int *lis)
{
	int	i;

	i = a->top + 1;
	lis[0] = size + 1;
	while (size >= 0)
	{
		while (result[--i] != size)
			;
		lis[size + 1] = a->st[i];
		--size;
	}
}

int	b_search(int *dp, int a, int s, int e)
{
	int	mid;

	mid = (s + e) / 2;
	if (s == e)
	{
		if (dp[s] < a)
			return (s);
		else
			return (-1);
	}
	if (dp[mid] > a)
		return (b_search(dp, a, mid + 1, e));
	else
		return (b_search(dp, a, s, mid));
}
