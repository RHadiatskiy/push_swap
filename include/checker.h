#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "structure.h"

int		ps_is_sort(int *arr, int n);
void	ps_sa(t_stack *stack, int n);
void	ps_sb(t_stack *stack, int n);
void	ps_ss(t_stack *stack, int n);
void	print_stacks(t_stack *stack, int n);

#endif