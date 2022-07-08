#include <stdio.h>

typedef struct s_stack
{
	int top;
	int st[5];
}	t_stack;
void    get_lis(t_stack *a, int *result, int size, int *lis);
void    lis_sort(t_stack *a, int *lis, int i);
int     b_search(int *dp, int a, int s, int e);


void    lis_sort(t_stack *a, int *lis, int i)
{
        int     size;
        int     pos;
        int     dp[5];
        int     result[5];

        size = 0;
        dp[0] = a->st[0];
        result[0] = 0;
        while (++i <= a->top)
        {
                if (dp[size] > a->st[i])
                {
                        dp[++size] = a->st[i];
                        pos = size;
                }
                else
                {
                        pos = b_search(dp, a->st[i], 0, size);
                        if (pos != -1 && pos <= size)
                                dp[pos] = a->st[i];
                }
                result[i] = pos;
        }
        get_lis(a, result, size, lis);
}

void    get_lis(t_stack *a, int *result, int size, int *lis)
{
        int     i;

        i = a->top + 1;
        lis[0] = size + 1;
        while (size >= 0)
        {
                while (result[--i] != size)
                        ;
                lis[size + 1] = a->st[i];
                --size;
        }
}

int     b_search(int *dp, int a, int s, int e)
{
        int     mid;

        mid = (s + e) / 2;
        if (s == e)
        {
                if (dp[s] < a)
                        return (s);
                else
                        return (-1);
	}
	if (dp[mid] > a)
		return (b_search(dp, a, mid + 1, e));
	else
		return (b_search(dp, a, s, mid));
}

void	get_a(t_stack *a)
{
	a->top = 4;
	a->st[0] = 2;
	a->st[1] = 1;
	a->st[2] = 3;
	a->st[3] = 5;
	a->st[4] = 4;
}

int main()
{
	int i = 1 / 2;
	t_stack a;
	int lis[6];
	
	get_a(&a);
	lis_sort(&a, lis, 0);

	for (int i = 0; i < 6; i++)
		printf("%d\n", lis[i]);
	for (int i = 0; i < 5; i++)
		printf("%d\n", a.st[i]);
}
