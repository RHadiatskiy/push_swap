/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_three_stack_func.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 20:45:36 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/04 20:45:38 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/structure.h"

void		sort_less_three_stack_a(t_info_list *info, t_size_list *size_list)
{
	if (ft_list_size(info->a) <= 3)
		sorting_algorithm_for_stack_a_less_three(info);
	else
		sort_more_three_stack_a(info, size_list);
}

void		sort_less_three_stack_reverse_a(t_info_list *info, \
	t_size_list *size_list)
{
	if (ft_list_size(info->a) <= 3)
		sorting_algorithm_for_stack_a_less_three(info);
	else
		sort_more_three_stack_reverse_a(info, size_list);
}

void		sorting_less_three_elem(t_info_list *info, t_size_list *size_list)
{
	if (info->b->data > info->b->next->data && info->b->data > \
		info->b->next->next->data)
	{
		ps_pa(info, 1);
		size_list->b_size--;
		if (info->b->data < info->b->next->data)
			ps_sb(info, 1);
	}
	else if (info->b->data < info->b->next->data && \
		info->b->data < info->b->next->next->data)
	{
		ps_rb(info, 1);
		if (info->b->data < info->b->next->data)
			ps_sb(info, 1);
	}
	else if ((info->b->next->next->data > info->b->next->data) && \
		(info->b->next->next->data > info->b->data))
	{
		if (info->b->data < info->b->next->data)
			ps_sb(info, 1);
		ps_rrb(info, 1);
	}
	else if (info->b->data < info->b->next->data)
		ps_sb(info, 1);
}

void		sort_less_three_stack_b(t_info_list *info, t_size_list *size_list)
{
	if (ft_list_size(info->b) <= 3)
	{
		if (ft_list_size(info->b) == 3)
			sorting_less_three_elem(info, size_list);
		else if (ft_list_size(info->b) == 2)
		{
			if (info->b->data < info->b->next->data)
				ps_sb(info, 1);
		}
		else
		{
			;
		}
	}
	else
		sort_more_three_stack_b(info, size_list);
}

void		sort_less_three_stack_reverse_b(t_info_list *info, \
	t_size_list *size_list)
{
	if (ft_list_size(info->b) <= 3)
	{
		if (ft_list_size(info->b) == 3)
			sorting_less_three_elem(info, size_list);
		else if (ft_list_size(info->b) == 2)
		{
			if (info->b->data < info->b->next->data)
				ps_sb(info, 1);
		}
		else
		{
			;
		}
	}
	else
		sort_more_three_stack_reverse_b(info, size_list);
}
