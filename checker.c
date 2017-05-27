#include "include/checker.h"
#include "include/structure.h"

int		main(int argc, char **argv)
{
	int			i;
	int			j;
	t_stack		*stack;

	i = 1;
	j = 0;
	if (!(stack = (t_stack *)malloc(sizeof(t_stack))) || \
		!(stack->a = (int *)malloc(sizeof(int) * argc)))
		return (-1);
	while (argc > i)
		stack->a[j++] = atoi(argv[i++]);
	i = 0;
	// if (ps_is_sort(stack->a, argc - 1) && argc > 1)
	// 	write(1, "\033[32mOK\033[0m\n", 15);
	// else
	// 	write(1, "\033[31mKO\033[0m\n	", 15);
	ps_ss(stack, argc - 1);	
	print_stacks(stack, argc - 1);
	ps_sa(stack, argc - 1);
	print_stacks(stack, argc - 1);
	stack->b = stack->a;
	ps_sa(stack, argc - 1);
	print_stacks(stack, argc - 1);

	return (0);
}