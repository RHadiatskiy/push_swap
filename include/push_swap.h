/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:24:42 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/22 17:19:26 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "structure.h"
# include "../libft/libft.h"

int			ft_list_size(t_stack *stack);
intmax_t	take_elem(t_stack *stack, int n);
t_stack		*ft_lstcpy(t_stack *stack);
t_stack		*ft_lstncpy(t_stack *stack, long n);
t_stack		*ft_sort_list(t_stack *stack);
int			swap_is_sort_a(t_stack *stack, int n);
int			swap_is_sort_b(t_stack *stack, int n);
void		sort_by_pivot_stack_a(t_info_list *info, t_size_list *size_list);
void		sort_by_pivot_stack_b(t_info_list *info, t_size_list *size_list);
t_size_list	*initial_size_list(void);
void		sort_less_three_stack_a(t_info_list *info, int size);
void		sort_less_three_stack_b(t_info_list *info, int size);
void		sort_by_pivot_stack_reverse_a(t_info_list *info, \
	t_size_list **size_list, int *i, int pivot);
void		sort_by_pivot_stack_reverse_b(t_info_list *info, \
	t_size_list **size_list, int *i, int pivot);
void		sorting_a_one(t_info_list *info);
void		sorting_a_two(t_info_list *info);
void		sorting_b_one(t_info_list *info);
void		sorting_b_two(t_info_list *info);
void		sorting_b_three(t_info_list *info);

#endif
