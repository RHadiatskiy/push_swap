/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_stack_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 16:02:18 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/11 16:02:20 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		sort_more_three_stack_b(t_info_list *info, int *size)
{
	if ((*size) == 2)
	{
		if (info->b->data < info->b->next->data)
			ps_sb(info, 1);
	}
	else if ((*size) == 3)
	{
		if (info->b->data > info->b->next->data && \
			info->b->data > info->b->next->next->data)
		{
			ps_pa(info, 1);
			(*size)--;
			if (info->b->data < info->b->next->data)
				ps_sb(info, 1);
		}
		else if ((info->b->next->next->data > info->b->next->data) && \
			(info->b->next->next->data > info->b->data))
			sorting_b_two(info);
		else if (info->b->next->data > info->b->data && \
			info->b->next->data > info->b->next->next->data)
			sorting_b_three(info);
	}
}

void		sort_more_three_stack_reverse_b(t_info_list *info, int *size)
{
	int				i;

	i = 0;
	while ((*size) > ++i)
		ps_rrb(info, 0);
	if (info->b->next->next->data > info->b->data && \
		info->b->next->next->data > info->b->next->data)
		sorting_algorithm_for_stack_reverse_b_add_1(info, &i, size);
	else if (info->b->data < info->b->next->data && \
		info->b->data < info->b->next->next->data && \
		info->b->next->data > info->b->next->next->data)
		sorting_algorithm_for_stack_reverse_b_add_2(info, &i, size);
	else
		sorting_algorithm_for_stack_reverse_b_add_3(info, &i, size);
/*	else
	{
		while (--i > 0)
			ps_rb(info, 0);
		while ((*size) > ++i)
			ps_rrb(info, 1);
		if ((*size) == 2)
		{
			if (info->b->data < info->b->next->data)
				ps_sb(info, 1);
		}
		else if ((*size) == 3)
		{
			if (info->b->data > info->b->next->data && \
				info->b->data > info->b->next->next->data && \
				info->b->next->data < info->b->next->next->data)
				sorting_b_one(info);
			else if ((info->b->next->next->data > info->b->next->data) && \
				(info->b->next->next->data > info->b->data))
				sorting_b_two(info);
			else if (info->b->next->data > info->b->data && \
				info->b->next->data > info->b->next->next->data)
				sorting_b_three(info);
			else if (info->b->data < info->b->next->data)
				ps_sb(info, 1);
		}
	} */
}

void		reverse_recursion_stack_b(t_info_list *info, t_size_list *size_list)
{
	intmax_t		pivot;
	int				size;
	t_size_list		*size_list_next;
	t_stack			*tmp;

	// dprintf(2, "\n\n%sREVERSE stack_b : %s\n", RED, RESET);
	// print_stack_list(info);
	// dprintf(2, "SIZE A: %ld\n", size_list->a_size);
	// dprintf(2, "SIZE B: %ld\n", size_list->b_size);
	tmp = NULL;
	size_list_next = initial_size_list();
	if ((size = size_list->b_size) <= 3)
	{
		sort_less_three_stack_reverse_b(info, &size);
		while (size-- != 0)
			ps_pa(info, 1);
	}
	else
	{
		tmp = ft_lstncpy(info->b, (ft_list_size(info->b) - size), size);
		pivot = take_elem(ft_sort_list(tmp), size / 2);
		// dprintf(2, "%sPIVOT : %jd%s\n",RED, pivot, RESET);
		size == ft_list_size(info->b) ? \
		sorting_stack_b(info, size_list_next, pivot, &size) : \
		reverse_sorting_stack_b(info, size_list_next, pivot, &size);
		sort_by_pivot_stack_a(info, size_list_next);
		sort_by_pivot_stack_b(info, size_list_next);
	}
	dealloc_stack(tmp);
	free(size_list_next);
}

void		sort_by_pivot_stack_b(t_info_list *info, t_size_list *size_list)
{
	intmax_t		pivot;
	int				size;
	t_size_list		*size_list_next;
	t_stack			*tmp;

	// dprintf(2, "\n\n%sSTACK_B : %s\n", RED, RESET);
	// print_stack_list(info);
	// dprintf(2, "SIZE A: %ld\n", size_list->a_size);
	// dprintf(2, "SIZE B: %ld\n", size_list->b_size);
	tmp = NULL;
	size_list_next = initial_size_list();
	if ((size = size_list->b_size) <= 3)
	{
		sort_less_three_stack_b(info, &size);
		while (size-- != 0)
			ps_pa(info, 1);
	}
	else
	{
		tmp = ft_lstncpy(info->b, 0, size);
		pivot = take_elem(ft_sort_list(tmp), size / 2);
		// dprintf(2, "%sPIVOT : %jd%s\n",RED, pivot, RESET);
		sorting_stack_b(info, size_list_next, pivot, &size);
		sort_by_pivot_stack_a(info, size_list_next);
		reverse_recursion_stack_b(info, size_list_next);
	}
	dealloc_stack(tmp);
	free(size_list_next);
}
