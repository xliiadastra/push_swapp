/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_option_reverse_rotate.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:52:19 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/08 18:55:13 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_stack *a)
{
	rotate(a, 1);
}

void	rrb(t_stack *b)
{
	rotate(b, 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	rotate(a, 1);
	rotate(b, 1);
}
