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

void		sort_more_three_stack_a(t_info_list *info, int size)
{
	if (size == 2)
	{
		if (info->a->data > info->a->next->data)
			ps_sa(info, 1);
	}
	else if (size == 3)
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

void		check_more_three_stack_a(t_info_list *info, int size)
{
	int				i;

	i = 0;
	while (size > ++i)
		ps_rra(info, 0);
	if (info->a->next->data > info->a->data && \
		info->a->next->data > info->a->next->next->data)
	{
		while (--i > 0)
			ps_ra(info, 0);
		while (size > ++i)
		{
			ps_rra(info, 1);
			if (info->a->data > info->a->next->data)
				ps_sa(info, 1);
		}
	}
	else
	{
		while (--i > 0)
			ps_ra(info, 0);
		while (size > ++i)
			ps_rra(info, 1);
	}
}

void		sort_more_three_stack_reverse_a(t_info_list *info, int size)
{
	check_more_three_stack_a(info, size);
	if (size == 2)
	{
		if (info->a->data > info->a->next->data)
			ps_sa(info, 1);
	}
	else if (size == 3)
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
	int				size;
	t_size_list		*size_list_next;
	t_stack			*tmp;

	// dprintf(2, "\n\n%sREVERSE stack_a : %s\n", GREEN, RESET);
	// print_stack_list(info);
	// dprintf(2, "SIZE A: %ld\n", size_list->a_size);
	// dprintf(2, "SIZE B: %ld\n", size_list->b_size);
	tmp = NULL;
	size_list_next = initial_size_list();
	if ((size = size_list->a_size) <= 3)
		sort_less_three_stack_reverse_a(info, size);
	else
	{
		tmp = ft_lstncpy(info->a, (ft_list_size(info->a) - size), size);
		pivot = take_elem(ft_sort_list(tmp), size / 2);
		// dprintf(2, "%sPIVOT : %jd%s\n",RED, pivot, RESET);
		if (size == ft_list_size(info->a))
			sorting_stack_a(info, size_list_next, pivot, &size);
		else
			reverse_sorting_stack_a(info, size_list_next, pivot, &size);
		sort_by_pivot_stack_a(info, size_list_next);
		sort_by_pivot_stack_b(info, size_list_next);
	}
	dealloc_stack(tmp);
	free(size_list_next);
}

void		sort_by_pivot_stack_a(t_info_list *info, t_size_list *size_list)
{
	intmax_t		pivot;
	int				size;
	t_size_list		*size_list_next;
	t_stack			*tmp;

	// dprintf(2, "\n\n%sstack_a : %s\n", GREEN, RESET);
	// print_stack_list(info);
	// dprintf(2, "SIZE A: %ld\n", size_list->a_size);
	// dprintf(2, "SIZE B: %ld\n", size_list->b_size);	
	tmp = NULL;
	size_list_next = initial_size_list();
	if ((size = size_list->a_size) <= 3)
		sort_less_three_stack_a(info, size);
	else
	{
		tmp = ft_lstncpy(info->a, 0, size);
		pivot = take_elem(ft_sort_list(tmp), size / 2);
		// dprintf(2, "%sPIVOT : %jd%s\n",RED, pivot, RESET);
		sorting_stack_a(info, size_list_next, pivot, &size);
		reverse_recursion_stack_a(info, size_list_next);
		sort_by_pivot_stack_b(info, size_list_next);
	}
	dealloc_stack(tmp);
	free(size_list_next);
}
