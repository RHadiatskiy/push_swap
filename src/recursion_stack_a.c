/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 16:02:09 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/11 16:02:11 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		sort_more_three_stack_a(t_info_list *info, t_size_list *size_list)
{
	if (size_list->a_size == 2)
	{
		if (info->a->data > info->a->next->data)
			ps_sa(info, 1);
	}
	else if (size_list->a_size == 3)
	{
		if (info->a->data > info->a->next->data && \
			info->a->data > info->a->next->next->data)
			sorting_a_one(info);
		else if ((info->a->next->data > info->a->data) && \
			(info->a->next->data > info->a->next->next->data))
			sorting_a_two(info);
		else if (info->a->next->next->data > info->a->data && \
			info->a->next->next->data > info->a->next->data)
		{
			if (info->a->data > info->a->next->data)
				ps_sa(info, 1);
		}
	}
	else
	{
		;
	}
}

void		check_more_three_stack_a(t_info_list *info, t_size_list *size_list)
{
	int				i;

	i = 1;
	while (size_list->position_a < --i)
		ps_rra(info, 0);
	if (info->a->next->data > info->a->data && \
		info->a->next->data > info->a->next->next->data)
	{
		while (++i < 1)
			ps_ra(info, 0);
		while (size_list->position_a < --i)
		{
			ps_rra(info, 1);
			if (info->a->data > info->a->next->data)
				ps_sa(info, 1);
		}
	}
	else
	{
		while (++i < 1)
			ps_ra(info, 0);
		while (size_list->position_a < --i)
			ps_rra(info, 1);
	}
}

void		sort_more_three_stack_reverse_a(t_info_list *info, \
	t_size_list *size_list)
{
	check_more_three_stack_a(info, size_list);
	if (size_list->a_size == 2)
	{
		if (info->a->data > info->a->next->data)
			ps_sa(info, 1);
	}
	else if (size_list->a_size == 3)
	{
		if (info->a->data > info->a->next->data && \
			info->a->data > info->a->next->next->data)
			sorting_a_one(info);
		else if (info->a->next->next->data > info->a->data && \
			info->a->next->next->data > info->a->next->data)
		{
			if (info->a->data > info->a->next->data)
				ps_sa(info, 1);
		}
	}
	else
	{
		;
	}
}

void		reverse_recursion_stack_a(t_info_list *info, t_size_list *size_list)
{
	intmax_t		pivot;
	t_size_list		*size_list_next;
	t_stack			*tmp;

	tmp = NULL;
	size_list_next = initial_size_list();
	if (size_list->a_size <= 3)
		sort_less_three_stack_reverse_a(info, size_list);
	else
	{
		tmp = ft_lstncpy(info->a, (ft_list_size(info->a) - size_list->a_size), \
			size_list->a_size);
		pivot = take_elem(ft_sort_list(tmp), size_list->a_size / 2);
		if (size_list->a_size == ft_list_size(info->a))
			sorting_stack_a(info, size_list_next, pivot, \
				(int)size_list->a_size);
		else
			reverse_sorting_stack_a(info, size_list_next, pivot, \
				(int)size_list->a_size);
		sort_by_pivot_stack_a(info, size_list_next);
		sort_by_pivot_stack_b(info, size_list_next);
	}
	dealloc_stack(tmp);
	free(size_list_next);
}

void		sort_by_pivot_stack_a(t_info_list *info, t_size_list *size_list)
{
	intmax_t		pivot;
	t_size_list		*size_list_next;
	t_stack			*tmp;

	tmp = NULL;
	size_list_next = initial_size_list();
	if (size_list->a_size <= 3)
		sort_less_three_stack_a(info, size_list);
	else
	{
		tmp = ft_lstncpy(info->a, 0, size_list->a_size);
		pivot = take_elem(ft_sort_list(tmp), size_list->a_size / 2);
		sorting_stack_a(info, size_list_next, pivot, (int)size_list->a_size);
		reverse_recursion_stack_a(info, size_list_next);
		sort_by_pivot_stack_b(info, size_list_next);
	}
	dealloc_stack(tmp);
	free(size_list_next);
}
