/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichoi <yichoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:02:11 by yichoi            #+#    #+#             */
/*   Updated: 2022/07/09 16:48:11 by yichoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	get_input(&a, &b);
	return (0);
}

void	get_input(t_stack *a, t_stack *b)
{
	char	*line;
	int		lis[ST_SIZE + 1];

	line = get_next_line(0);
	while (line)
	{
		ft_parse(line, a, b);
		free(line);
		line = 0;
		line = get_next_line(0);
	}
	free(line);
	line = 0;
	lis_sort(a, lis, 0);
	if (lis[0] == a->top + 1 && b->top == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
