/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:10:23 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/31 18:10:25 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			ps_is_sort(t_info_list *info)
{
	t_stack		*stack_a;

	stack_a = info->a;
	if (!info && !info->a)
		return (-1);
	if (ft_list_size(info->b) != 0)
		return (write(1, "KO\n", 3));
	while (stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (write(1, "KO\n", 3));
		stack_a = stack_a->next;
	}
	return (write(1, "OK\n", 3));
}

int			swap_is_sort_a(t_stack *stack, int n)
{
	int		i;

	i = 0;
	if (!stack)
		return (-1);
	while (stack->next && i < n)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

int			swap_is_sort_b(t_stack *stack, int n)
{
	int		i;

	i = 0;
	if (!stack)
		return (-1);
	while (stack->next && i < n)
	{
		if (stack->data < stack->next->data)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

t_stack		*ft_sort_list(t_stack *stack)
{
	t_stack		*tmp1;
	t_stack		*tmp2;
	intmax_t	ret;

	ret = 0;
	tmp1 = stack;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->data > tmp2->data)
			{
				ret = tmp1->data;
				tmp1->data = tmp2->data;
				tmp2->data = ret;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (stack);
}
