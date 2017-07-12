/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:10:07 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/31 18:10:10 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/structure.h"
#include "../include/checker.h"
#include "../include/push_swap.h"

void		stack_list_added(t_stack *stack, intmax_t data)
{
	t_stack		*temp;

	if ((temp = (t_stack *)malloc(sizeof(t_stack))))
	{
		if (stack->n == 0)
		{
			stack->data = data;
			stack->n = stack->n + 1;
		}
		else
		{
			while (stack->next)
				stack = stack->next;
			temp->data = data;
			temp->next = NULL;
			stack->next = temp;
		}
	}
}

int			ft_list_size(t_stack *stack)
{
	int		size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stack		*ft_lstcpy(t_stack *stack)
{
	t_stack		*tmp;

	if (!stack)
		return (NULL);
	tmp = create_stack_list();
	while (stack)
	{
		stack_list_added(tmp, stack->data);
		stack = stack->next;
	}
	return (tmp);
}

t_stack		*ft_lstncpy(t_stack *stack, long n)
{
	t_stack			*tmp;
	unsigned int	i;

	i = 0;
	if (!stack || n <= 0)
		return (NULL);
	tmp = create_stack_list();
	while (stack && i++ < n)
	{
		stack_list_added(tmp, stack->data);
		stack = stack->next;
	}
	return (tmp);
}

void		print_stack_list(t_info_list *info)
{
	t_stack		*a_temp;
	t_stack		*b_temp;

	dprintf(2, "\n%sSTACK A:%s\n", WHITE, RESET);
	if (info->a)
	{
		a_temp = info->a;
		while (a_temp->next)
		{
			dprintf(2, "%s%jd%s ", GREEN, a_temp->data, RESET);
			a_temp = a_temp->next;
		}
		dprintf(2, "%s%jd%s\n", GREEN, a_temp->data, RESET);
	}
	dprintf(2, "%sSTACK B:%s\n", WHITE, RESET);
	if (info->b)
	{
		b_temp = info->b;
		while (b_temp->next)
		{
			dprintf(2, "%s%jd%s ", RED, b_temp->data, RESET);
			b_temp = b_temp->next;
		}
		dprintf(2, "%s%jd%s\n", RED, b_temp->data, RESET);
	}
}
