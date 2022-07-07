/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_enqueue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:04:04 by yichoi            #+#    #+#             */
/*   Updated: 2022/05/29 21:39:36 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void     str_enqueue_str(t_stack *a, const char *str);
static void     enqueue_number(t_stack *a, int number);
static void     rev_arr(t_stack *a);

static void	str_enqueue_str(t_stack *a, const char *str)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_split(str, ' ');
	if (!split)
		ft_error();
	while (split[++i])
		enqueue_number(a, push_swap_atoi(str));
	split_free(split);
}

static void	enqueue_number(t_stack *a, int number)
{
	if (a->top + 1 >= ST_SIZE)
		ft_error();
	a->st[++a->top] = number;
}

static void	rev_arr(t_stack *a)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = 0;
	while ((++i < (a->top / 2)))
	{
		tmp = a->st[i];
		a->st[i] = a->st[a->top - i];
		a->st[a->top - i] = tmp;
	}
}

void	str_enqueue(t_stack *a, char *argv[])
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_strchr(argv[i], ' '))
			str_enqueue_str(a, argv[i]);
		else
			enqueue_number(a, push_swap_atoi(argv[i]));
	}
	rev_arr(a);
}
