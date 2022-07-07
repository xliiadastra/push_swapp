/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:50:59 by yichoi            #+#    #+#             */
/*   Updated: 2022/05/29 22:57:17 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stack *a)
{
	rotate(a, 0);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b, 0);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, 0);
	rotate(b, 0);
	write(1, "rr\n", 3);
}
