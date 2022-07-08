/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_option_tool.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:01:50 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/08 17:02:25 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_stack *s)
{
	int	tmp;

	if (s->top < 1)
		return ;
	tmp = s->st[s->top];
	s->st[s->top] = s->st[s->top - 1];
	s->st[s->top - 1] = tmp;
}

void	push(t_stack *from, t_stack *to)
{
	if (to->top + 1 >= ST_SIZE)
		ft_error();
	if (from->top == -1)
		return ;
	to->st[++to->top] = from->st[from->top--];
}

void	rotate(t_stack *ro, int reverse)
{
	int	tmp;
	int	i;

	if (ro->top < 1)
		return ;
	if (!reverse)
	{
		i = ro->top;
		tmp = ro->st[ro->top];
		while (--i >= 0)
			ro->st[i + 1] = ro->st[i];
		ro->st[0] = tmp;
	}
	else
	{
		i = -1;
		tmp = ro->st[0];
		while (++i < ro->top)
			ro->st[i] = ro->st[i + 1];
		ro->st[ro->top] = tmp;
	}
}
