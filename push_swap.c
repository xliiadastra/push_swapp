/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:02:11 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/23 18:55:08 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	a;
	t_stack	b;

	i = 0;
	if (argc < 2)
		return (0);
	while (++i < argc)
		check_integer(argv[i]);
	start_stack(&a, &b);
	str_enqueue(&a, argv);
	check_dup(&a);
	stack_sort(&a, &b);
	return (0);
}
