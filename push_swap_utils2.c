/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:00:37 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/06 22:12:54 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_rr(t_stack *a, t_stack *b, int b_ts, int a_ts)
{
	if (b_ts > a_ts)
	{
		while (b_ts > a_ts++)
			rrb(b);
		while (b_ts++ < 0)
			rrr(a, b);
	}
	else
	{

	}
}
