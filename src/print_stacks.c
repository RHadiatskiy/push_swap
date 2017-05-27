#include "../include/checker.h"
#include "../include/structure.h"

void	print_stacks(t_stack *stack, int n)
{
	int		i;

	i = 0;
	printf("STACK: A");
	printf("\tSTACK: B\n");
	while (n > i)
	{
		if (stack->a)
			printf("| %d |", stack->a[i]);
		if (stack->b)
			printf("\t\t| %d |\n", stack->b[i]);
		else
			printf("\n");
		i++;
	}
}