#include "../include/checker.h"
#include "../include/structure.h"

void	ps_pa(t_stack *stack, int n)
{
	int		tmp;
	int		i;
	int		*arr;

	tmp = 0;
	i = 0;
	if (n > 1 && stack->a && stack->b)
	{
		if (!(arr = (int *)malloc(sizeof(int) * n - 1)))
			return (NULL);
		while (stack->b[i])
			i++;
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
}
