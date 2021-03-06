/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition_functions_for_sorting.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 16:50:22 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/15 16:50:24 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/structure.h"

void		sorting_algorithm_for_stack_a_less_three(t_info_list *info)
{
	while (!swap_is_sort_a(info->a, ft_list_size(info->a)))
	{
		if (ft_list_size(info->a) == 3)
		{
			if (info->a->data > info->a->next->data && \
				info->a->data > info->a->next->next->data)
				ps_ra(info, 1);
			else if ((info->a->next->next->data < info->a->next->data) || \
				(info->a->next->next->data < info->a->data))
				ps_rra(info, 1);
			else if (info->a->data > info->a->next->data)
				ps_sa(info, 1);
		}
		else if (ft_list_size(info->a) == 2)
		{
			if (info->a->data > info->a->next->data)
				ps_sa(info, 1);
		}
		else
		{
			;
		}
	}
}

void		sorting_algorithm_for_stack_reverse_b_add_1(t_info_list *info, \
	int *i, t_size_list *size_list)
{
	while (++(*i) < 1)
		ps_rb(info, 0);
	if (size_list->b_size == (size_list->position_b * -1))
	{
		ps_rrb(info, 1);
		size_list->position_b++;
	}
	ps_pa(info, 1);
	size_list->b_size--;
	while (size_list->position_b < --(*i))
		ps_rrb(info, 1);
	if (info->b->data < info->b->next->data)
		ps_sb(info, 1);
}

void		sorting_algorithm_for_stack_reverse_b_add_2(t_info_list *info, \
	int *i, t_size_list *size_list)
{
	while (++(*i) < 1)
		ps_rb(info, 0);
	while (size_list->position_b < --(*i))
		ps_rrb(info, 1);
	sorting_b_three(info);
}

void		sorting_algorithm_for_stack_reverse_b_add_3(t_info_list *info, \
	int *i, t_size_list *size_list)
{
	while (++(*i) < 1)
		ps_rb(info, 0);
	while (size_list->position_b < --(*i))
	{
		ps_rrb(info, 1);
		if (info->b->data < info->b->next->data)
			ps_sb(info, 1);
	}
}
