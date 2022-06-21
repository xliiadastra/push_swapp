/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 18:39:32 by yichoi            #+#    #+#             */
/*   Updated: 2022/05/29 21:55:25 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_integer_str(char *str)
{
	char	**split;
	int		i;
	int		j;

	split = ft_split(str, ' ');
	if (!split)
		ft_error();
	i = -1;
	if (!split[0])
		ft_error();
	while (split[++i])
		check_integer_number(split[i]);
	split_free(split);
}

static void	check_integer_number(char *str)
{
	if (*str == '+' || *str == '-')
		++str;
	if (!(*str))
		ft_error();
	while (*str)
		if (!(ft_isdigit(str++)))
			ft_error();
}

void	check_integer(char *str)
{
	if (ft_strchr(str, ' '))
		check_integer_str(str);
	else
		check_integer_number(str);
}

void	check_dup(t_stack *a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < a->top)
	{
		j = i;
		while (++j <= a->top)
			if (a->st[i] == a->st[j])
				ft_error();
	}
}
