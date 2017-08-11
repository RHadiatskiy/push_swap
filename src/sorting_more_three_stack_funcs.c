/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_more_three_stack_funcs.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 15:37:00 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/11 15:37:03 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../include/push_swap.h"

void		sorting_a_one(t_info_list *info)
{
	if (info->a->data > info->a->next->data && \
		info->a->data > info->a->next->next->data)
	{
		ps_sa(info, 1);
		ps_ra(info, 1);
		ps_sa(info, 1);
		ps_rra(info, 1);
		if (info->a->data > info->a->next->data)
			ps_sa(info, 1);
	}
}

void		sorting_a_two(t_info_list *info)
{
	if ((info->a->next->data > info->a->data) && \
		(info->a->next->data > info->a->next->next->data))
	{
		ps_ra(info, 1);
		ps_sa(info, 1);
		ps_rra(info, 1);
		if (info->a->data > info->a->next->data)
			ps_sa(info, 1);
	}
}

void		sorting_b_one(t_info_list *info)
{
	if (info->b->data > info->b->next->data && \
		info->b->data > info->b->next->next->data)
	{
		ps_rb(info, 1);
		if (info->b->data < info->b->next->data)
			ps_sb(info, 1);
		ps_rrb(info, 1);
	}
}

void		sorting_b_two(t_info_list *info)
{
	if ((info->b->next->next->data > info->b->next->data) && \
		(info->b->next->next->data > info->b->data))
	{
		if (info->b->data < info->b->next->data)
			ps_sb(info, 1);
		ps_rb(info, 1);
		ps_sb(info, 1);
		ps_rrb(info, 1);
		if (info->b->data < info->b->next->data)
			ps_sb(info, 1);
	}
}

void		sorting_b_three(t_info_list *info)
{
	if (info->b->next->data > info->b->data && \
		info->b->next->data > info->b->next->next->data)
	{
		ps_sb(info, 1);
		if (info->b->next->data < info->b->next->next->data)
		{
			ps_rb(info, 1);
			ps_sb(info, 1);
			ps_rrb(info, 1);
		}
	}
}
