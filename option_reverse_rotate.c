/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_reverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:52:19 by yichoi            #+#    #+#             */
/*   Updated: 2022/05/29 22:58:24 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	rotate(a, 1);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	rotate(b, 1);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rotate(a, 1);
	rotate(b, 1);
	write(1, "rrr\n", 4);
}
