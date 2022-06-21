# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
/*   option_swap.c                                      :+:      :+:    :+:   */
#                                                     +:+ +:+         +:+      #
#    By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 19:40:19 by yichoi            #+#    #+#              #
/*   Updated: 2022/05/29 22:50:07 by yichoi           ###   ########.fr       */
#                                                                              #
# **************************************************************************** #

#include "push_swap.h"

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
