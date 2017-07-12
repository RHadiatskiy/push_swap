/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_creating_lists.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 15:47:07 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/11 15:47:11 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/structure.h"
#include "../include/checker.h"
#include "../include/push_swap.h"

t_stack			*create_stack_list(void)
{
	t_stack			*stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	stack->data = 0;
	stack->next = NULL;
	stack->n = 0;
	return (stack);
}

t_size_list		*initial_size_list(void)
{
	t_size_list		*new_list;

	if (!(new_list = (t_size_list *)malloc(sizeof(t_size_list))))
		return (NULL);
	new_list->a_size = 0;
	new_list->b_size = 0;
	new_list->position_a = 0;
	new_list->position_b = 0;
	return (new_list);
}

t_info_list		*initial_info_list(void)
{
	t_info_list		*info;

	if (!(info = (t_info_list *)malloc(sizeof(t_info_list))))
		return (NULL);
	info->a = create_stack_list();
	info->b = NULL;
	info->flag_v = 0;
	info->flag_c = 0;
	info->i = 0;
	return (info);
}
