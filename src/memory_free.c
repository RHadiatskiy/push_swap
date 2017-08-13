/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:05:23 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/13 18:05:25 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/structure.h"
#include "../include/checker.h"

void		del(t_info_list *start)
{
	dealloc_stack(start->a);
	dealloc_stack(start->b);
	free(start);
}

void		dealloc_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->next)
			dealloc_stack(stack->next);
		ft_bzero(stack, sizeof(stack));
		free(stack);
	}
}
