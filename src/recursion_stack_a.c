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
#include "../include/structure.h"
#include "../include/checker.h"

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
}

void		sort_more_three_stack_reverse_a(t_info_list *info, int size)
{
	int				i;

	i = 0;
	while (size > ++i)
		ps_rra(info, 1);
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
}

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

void		sorting_stack_a(t_info_list *info, t_size_list *size_list_next, int pivot, int *size)
{
	while ((*size)-- > 1)
	{
		if ((info->a->data) <= pivot)
		{
			ps_pb(info, 1);
			size_list_next->b_size++;
		}
		else
		{
			ps_ra(info, 1);
			size_list_next->a_size++;
		}
	}
	if ((info->a->data) <= pivot)
	{
		ps_pb(info, 1);
		ps_rra(info, 1);
		size_list_next->b_size++;
	}
	else
		size_list_next->a_size++;
}

void		reverse_recursion_stack_a(t_info_list *info, t_size_list *size_list)
{
	intmax_t		pivot;
	int				size;
	t_size_list 	*size_list_next;
	
	dprintf(2, "\n\n%sREVERSE stack_a : %s\n", GREEN, RESET);
	print_stack_list(info);
	dprintf(2, "SIZE A: %ld\n", size_list->a_size);
	dprintf(2, "SIZE B: %ld\n", size_list->b_size);

	size_list_next = initial_size_list();
	if ((size = size_list->a_size) <= 3)
		sort_less_three_stack_reverse_a(info, size);
	else
	{
		pivot = take_elem(ft_sort_list(ft_lstncpy(info->a, (ft_list_size(info->a) - size), size)), size / 2);
		dprintf(2, "%sPIVOT : %jd%s\n",RED, pivot, RESET);
		// sorting_stack_a(info, size_list_next, pivot, &size);

		while (size-- > 1)
		{
			if ((info->a->data) <= pivot)
			{
				ps_pb(info, 1);
				size_list_next->b_size++;
			}
			else
				size_list_next->a_size++;
			ps_rra(info, 1);
		}
		if ((info->a->data) <= pivot)
		{
			ps_pb(info, 1);
			size_list_next->b_size++;
		}
		else
			size_list_next->a_size++;
		sort_by_pivot_stack_a(info, size_list_next);
		sort_by_pivot_stack_b(info, size_list_next);
	}
	free(size_list_next);
}

void		sort_by_pivot_stack_a(t_info_list *info, t_size_list *size_list)
{
	intmax_t		pivot;
	int				size;
	t_size_list 	*size_list_next;
	
	dprintf(2, "\n\n%sstack_a : %s\n", GREEN, RESET);
	print_stack_list(info);
	dprintf(2, "SIZE A: %ld\n", size_list->a_size);
	dprintf(2, "SIZE B: %ld\n", size_list->b_size);	

	size_list_next = initial_size_list();
	if ((size = size_list->a_size) <= 3)
		sort_less_three_stack_a(info, size);
	else
	{
		pivot = take_elem(ft_sort_list(ft_lstncpy(info->a, 0, size)), size / 2);
		dprintf(2, "%sPIVOT : %jd%s\n",RED, pivot, RESET);

		sorting_stack_a(info, size_list_next, pivot, &size);

		// if (ft_list_size(info->a) != 0)
		// 	while (i++ < size_list_next->a_size)
		// 		ps_rra(info, 1);

		reverse_recursion_stack_a(info, size_list_next);
		sort_by_pivot_stack_b(info, size_list_next);
	}
	free(size_list_next);
}
