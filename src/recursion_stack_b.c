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
#include "../include/structure.h"
#include "../include/checker.h"

void		sort_more_three_stack_b(t_info_list *info, int size)
{
	if (size == 2)
	{
		if (info->b->data < info->b->next->data)
			ps_sb(info, 1);
	}
	else if (size == 3)
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
}

void		sort_more_three_stack_reverse_b(t_info_list *info, int *size)
{
	int				i;

	i = 0;
	while ((*size) > ++i)
		ps_rrb(info, 0);
	if (info->b->next->next->data > info->b->data && \
		info->b->next->next->data > info->b->next->data)
	{
		while (--i > 0)
			ps_rb(info, 0);
		ps_pa(info, 1);
		(*size)--;
		while ((*size) > i++)
			ps_rrb(info, 1);
		if (info->b->data < info->b->next->data)
			ps_sb(info, 1);
	}
	else if (info->b->data < info->b->next->data && \
		info->b->data < info->b->next->next->data && \
		info->b->next->data > info->b->next->next->data)
	{
		ps_rb(info, 0);
		ps_rb(info, 0);
		ps_rrb(info, 1);
		ps_rrb(info, 1);
		sorting_b_three(info);
	}
	else
	{
		while (--i > 0)
			ps_rb(info, 0);
		while ((*size) > ++i)
		{
			ps_rrb(info, 1);
			if (info->b->data < info->b->next->data)
				ps_sb(info, 1);
		}
	}
	// else
	// {
	// 	while (--i > 0)
	// 		ps_rb(info, 0);
	// 	while ((*size) > ++i)
	// 		ps_rrb(info, 1);
	// 	if ((*size) == 2)
	// 	{
	// 		if (info->b->data < info->b->next->data)
	// 			ps_sb(info, 1);
	// 	}
	// 	else if ((*size) == 3)
	// 	{
	// 		if (info->b->data > info->b->next->data && \
	// 			info->b->data > info->b->next->next->data && \
	// 			info->b->next->data < info->b->next->next->data)
	// 			sorting_b_one(info);
	// 		else if ((info->b->next->next->data > info->b->next->data) && \
	// 			(info->b->next->next->data > info->b->data))
	// 			sorting_b_two(info);
	// 		else if (info->b->next->data > info->b->data && \
	// 			info->b->next->data > info->b->next->next->data)
	// 			sorting_b_three(info);
	// 		else if (info->b->data < info->b->next->data)
	// 			ps_sb(info, 1);
	// 	}
	// }
}

void		reverse_recursion_stack_b(t_info_list *info, t_size_list *size_list)
{
	intmax_t		pivot;
	int				size;
	t_size_list 	*size_list_next;
	
	// dprintf(2, "\n\n%sREVERSE stack_b : %s\n", RED, RESET);
	// print_stack_list(info);
	// dprintf(2, "SIZE A: %ld\n", size_list->a_size);
	// dprintf(2, "SIZE B: %ld\n", size_list->b_size);
	size_list_next = initial_size_list();
	if ((size = size_list->b_size) <= 3)
	{
		sort_less_three_stack_reverse_b(info, &size);
		while (size-- != 0)
			ps_pa(info, 1);
	}
	else
	{
		pivot = take_elem(ft_sort_list(ft_lstncpy(info->b, (ft_list_size(info->b) - size), size)), size / 2);
		// dprintf(2, "%sPIVOT : %jd%s\n",RED, pivot, RESET);
		if (size == ft_list_size(info->b))
			sorting_stack_b(info, size_list_next, pivot, &size);
		else
			reverse_sorting_stack_b(info, size_list_next, pivot, &size);
		sort_by_pivot_stack_a(info, size_list_next);
		sort_by_pivot_stack_b(info, size_list_next);
	}
	free(size_list_next);
}

void		sort_by_pivot_stack_b(t_info_list *info, t_size_list *size_list)
{
	intmax_t		pivot;
	int				size;
	t_size_list 	*size_list_next;
	
	// dprintf(2, "\n\n%sSTACK_B : %s\n", RED, RESET);
	// print_stack_list(info);
	// dprintf(2, "SIZE A: %ld\n", size_list->a_size);
	// dprintf(2, "SIZE B: %ld\n", size_list->b_size);
	size_list_next = initial_size_list();
	if ((size = size_list->b_size) <= 3)
	{
		sort_less_three_stack_b(info, size);
		while (size-- != 0)
			ps_pa(info, 1);
	}
	else
	{
		pivot = take_elem(ft_sort_list(ft_lstncpy(info->b, 0, size)), size / 2);
		// dprintf(2, "%sPIVOT : %jd%s\n",RED, pivot, RESET);
		sorting_stack_b(info, size_list_next, pivot, &size);
		sort_by_pivot_stack_a(info, size_list_next);
		reverse_recursion_stack_b(info, size_list_next);
	}
	free(size_list_next);
}
