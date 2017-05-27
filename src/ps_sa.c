#include "../include/checker.h"
#include "../include/structure.h"

void	ps_sa(t_stack *stack, int n)
{
	int		tmp;

	tmp = 0;
	if (n > 1 && stack->a)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
}
