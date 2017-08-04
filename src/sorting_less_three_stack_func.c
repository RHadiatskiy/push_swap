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
#include "../include/checker.h"

void		sort_less_three_stack_a(t_info_list *info, int size)
{
	if (ft_list_size(info->a) <= 3)
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
			else
			{
				if (info->a->data > info->a->next->data)
					ps_sa(info, 1);
			}
		}
	}
	else
		sort_more_three_stack_a(info, size);
}

void		sort_less_three_stack_reverse_a(t_info_list *info, int size)
{
	if (ft_list_size(info->a) <= 3)
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
			else
			{
				if (info->a->data > info->a->next->data)
					ps_sa(info, 1);
			}
		}
	}
	else
		sort_more_three_stack_reverse_a(info, size);
}

void		sort_less_three_stack_b(t_info_list *info, int size)
{
	if (ft_list_size(info->b) <= 3)
	{
		while (!swap_is_sort_b(info->b, ft_list_size(info->a)))
		{
			if (ft_list_size(info->b) == 3)
			{
				if (info->b->data < info->b->next->data && \
					info->b->data < info->b->next->next->data)
					ps_rb(info, 1);
				else if ((info->b->next->next->data > info->b->next->data) || \
					(info->b->next->next->data > info->b->data))
					ps_rrb(info, 1);
				else if (info->b->data < info->b->next->data)
					ps_sb(info, 1);
			}
			else
			{
				if (info->b->data < info->b->next->data)
					ps_sb(info, 1);
			}
		}
	}
	else
		sort_more_three_stack_b(info, size);
}

void		sort_less_three_stack_reverse_b(t_info_list *info, int size)
{
	if (ft_list_size(info->b) <= 3)
	{
		while (!swap_is_sort_b(info->b, ft_list_size(info->a)))
		{
			if (ft_list_size(info->b) == 3)
			{
				if (info->b->data < info->b->next->data && \
					info->b->data < info->b->next->next->data)
					ps_rb(info, 1);
				else if ((info->b->next->next->data > info->b->next->data) || \
					(info->b->next->next->data > info->b->data))
					ps_rrb(info, 1);
				else if (info->b->data < info->b->next->data)
					ps_sb(info, 1);
			}
			else
			{
				if (info->b->data < info->b->next->data)
					ps_sb(info, 1);
			}
		}
	}
	else
		sort_more_three_stack_reverse_b(info, size);
}
