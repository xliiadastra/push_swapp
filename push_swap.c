/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:02:11 by yichoi            #+#    #+#             */
/*   Updated: 2022/06/14 23:01:28 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*lis(char *sort, int end)
{
	char	arr[5];
	int	start;
	int	i;

	start = 0;
	i = 0;
	arr[0] = sort[0];
	while (start < end)
	{
		if (arr[i] < sort[start])
		{
			i++;
			arr[i] = sort[start];
		}
		start++;
	}
	return (arr);
}

int	main(int argc, char *argv[])
{
	int		i;
//	t_stack	*a_head;
//	t_stack	*b_head;
//	t_list	*a;
//	t_list	*b;
	t_stack	a;
	t_stack	b;

//	a = malloc(sizeof(t_stack));
//	b = malloc(sizeof(t_stack));
//	if (!a || !b)
//		ft_error(void);
//	a_head = a;
//	b_head = b;
	i = 0;
	if (argc < 2)
		return (0);
	while (++i < argc)
		check_integer(argv[i]);
	start_stack(&a, &b);
	str_enqueue(&a, argv);
	check_dup(&a);
//	stack_sort(&a, &b);
	return (0);
}
