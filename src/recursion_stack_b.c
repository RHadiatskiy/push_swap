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

void		sort_more_three_stack_reverse_b(t_info_list *info, int size)
{
	int				i;

	i = 0;
	while (size > i++)
		ps_rrb(info, 1);
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

void		sorting_stack_b(t_info_list *info, t_size_list *size_list_next, int pivot, int *size)
{
	while ((*size)-- > 0)
	{
		if ((info->b->data) > pivot)
		{
			ps_pa(info, 1);
			size_list_next->a_size++;
		}
		else
		{
			ps_rb(info, 1);
			size_list_next->b_size++;
		}
	}
}

void		reverse_recursion_stack_b(t_info_list *info, t_size_list *size_list)
{
	intmax_t		pivot;
	int				size;
	int				i;
	t_size_list 	*size_list_next;
	
	// print_stack_list(info);

	i = 0;
	size_list_next = initial_size_list();
	if ((size = size_list->b_size) <= 3)
	{
		sort_less_three_stack_reverse_b(info, size);
		while (size-- != 0)
			ps_pa(info, 1);
	}
	else
	{
		pivot = take_elem(ft_sort_list(ft_lstncpy(info->b, size)), size / 2);

		// printf("PIVOT : %jd\n", pivot);

		// sorting_stack_b(info, size_list_next, pivot, &size);

		// printf("SIZE A: %ld\n", size_list->a_size);
		// printf("SIZE B: %ld\n", size_list->b_size);
		while (size-- > 0)
		{
			ps_rrb(info, 1);
			if ((info->b->data) > pivot)
			{
				ps_pa(info, 1);
				size_list_next->a_size++;
			}
			else
				size_list_next->b_size++;
		}

		sort_by_pivot_stack_a(info, size_list_next);
		sort_by_pivot_stack_b(info, size_list_next);
	}
	free(size_list_next);
}

void		sort_by_pivot_stack_b(t_info_list *info, t_size_list *size_list)
{
	intmax_t		pivot;
	int				size;
	int				i;
	t_size_list 	*size_list_next;
	
	// print_stack_list(info);
	
	i = 0;
	size_list_next = initial_size_list();
	if ((size = size_list->b_size) <= 3)
	{
		sort_less_three_stack_b(info, size);
		while (size-- != 0)
			ps_pa(info, 1);
	}
	else
	{
		pivot = take_elem(ft_sort_list(ft_lstncpy(info->b, size)), size / 2);

		// printf("PIVOT : %jd\n", pivot);

		sorting_stack_b(info, size_list_next, pivot, &size);

		// printf("SIZE A: %ld\n", size_list->a_size);
		// printf("SIZE B: %ld\n", size_list->b_size);

		// if (ft_list_size(info->b) != 0)
		// 	while (i++ < size_list_next->b_size)
		// 		ps_rrb(info, 1);

		sort_by_pivot_stack_a(info, size_list_next);
		reverse_recursion_stack_b(info, size_list_next);
	}
	free(size_list_next);
}
