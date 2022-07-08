#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# define ST_SIZE 1000

typedef struct s_stack
{
	int	top;
	int	st[ST_SIZE];
}	t_stack;

void    get_input(t_stack *a, t_stack *b);

void    check_integer(char *str);
void    check_dup(t_stack *a);

void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    swap(t_stack *s);
void    push(t_stack *from, t_stack *to);
void    rotate(t_stack *ro, int reverse);

void    ft_parse(char *s, t_stack *a, t_stack *b);
void    ft_parse_s(char *s, t_stack *a, t_stack *b);
void    ft_parse_p(char *s, t_stack *a, t_stack *b);
void    ft_parse_r(char *s, t_stack *a, t_stack *b);

void	stack_sort(t_stack *a, t_stack *b);

void    lis_sort(t_stack *a, int *lis, int i);
void    get_lis(t_stack *a, int *result, int size, int *lis);
int     b_search(int *dp, int a, int s, int e);

void    str_enqueue(t_stack *a, char *argv[]);
void    ft_error(void);
void    split_free(char **str);
void    start_stack(t_stack *start1, t_stack *start2);
int     push_swap_atoi(const char *str);

#endif
