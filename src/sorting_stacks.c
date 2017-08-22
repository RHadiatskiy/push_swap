/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 20:34:56 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/04 20:34:57 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/structure.h"

void		sorting_stack_a(t_info_list *info, t_size_list *size_list_next, \
	int pivot, int size)
{
	while (size-- > 1)
	{
		if ((info->a->data) < pivot)
		{
			ps_pb(info, 1);
			size_list_next->b_size++;
		}
		else
		{
			ps_ra(info, 1);
			size_list_next->a_size++;
			size_list_next->position_a--;
		}
	}
	if ((info->a->data) < pivot)
	{
		ps_pb(info, 1);
		if (size_list_next->a_size != ft_list_size(info->a))
			ps_rra(info, 1);
		size_list_next->position_a++;
		size_list_next->b_size++;
	}
	else
		size_list_next->a_size++;
}

void		reverse_sorting_stack_a(t_info_list *info, t_size_list \
	*size_list_next, int pivot, int size)
{
	while (size-- > 1)
	{
		if ((info->a->data) < pivot)
		{
			ps_pb(info, 1);
			size_list_next->b_size++;
		}
		else
			size_list_next->a_size++;
		ps_rra(info, 1);
		size_list_next->position_a++;
	}
	if ((info->a->data) < pivot)
	{
		ps_pb(info, 1);
		size_list_next->b_size++;
	}
	else
		size_list_next->a_size++;
}

void		sorting_stack_b(t_info_list *info, t_size_list *size_list_next, \
	int pivot, int size)
{
	while (size-- > 1)
	{
		if (info->a->data - 1 == info->b->data && size_list_next->a_size == 0)
			ps_pa(info, 1);
		else if ((info->b->data) > pivot)
		{
			ps_pa(info, 1);
			size_list_next->a_size++;
		}
		else
		{
			ps_rb(info, 1);
			size_list_next->b_size++;
			size_list_next->position_b--;
		}
	}
	if ((info->b->data) > pivot)
	{
		ps_pa(info, 1);
		if (size_list_next->b_size != ft_list_size(info->b))
			ps_rrb(info, 1);
		size_list_next->a_size++;
		size_list_next->position_b++;
	}
	else
		size_list_next->b_size++;
}

void		reverse_sorting_stack_b(t_info_list *info, t_size_list \
	*size_list_next, int pivot, int size)
{
	while (size-- > 1)
	{
		if (info->a->data - 1 == info->b->data && size_list_next->a_size == 0)
			ps_pa(info, 1);
		else if ((info->b->data) > pivot)
		{
			ps_pa(info, 1);
			size_list_next->a_size++;
		}
		else
			size_list_next->b_size++;
		ps_rrb(info, 1);
		size_list_next->position_b++;
	}
	if ((info->b->data) > pivot)
	{
		ps_pa(info, 1);
		size_list_next->a_size++;
	}
	else
		size_list_next->b_size++;
}
