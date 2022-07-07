/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:54:42 by yichoi            #+#    #+#             */
/*   Updated: 2022/05/29 21:18:35 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	split_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}

void	start_stack(t_stack *start1, t_stack *start2)
{
	start1->top = -1;
	start2->top = -1;
}

int	push_swap_atoi(const char *str)
{
	char				sign;
	long long			result;

	result = 0;
	sign = 1;
	while (ft_isspace(*str) && *str)
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	if (result * sign > INT_MAX || result * sign < INT_MIN)
		ft_error();
	return ((int)(result * sign));
}
