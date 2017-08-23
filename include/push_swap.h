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

/*
** Colorize an output of printf
*/

# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define YELLOW		"\033[1;33m"
# define WHITE		"\033[1;37m"
# define GREEN		"\033[1;32m"

/*
** ----------------------------
*/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

# include "structure.h"
# include "../libft/libft.h"

/*
**			PUSH_SWAP
*/

int			ft_list_size(t_stack *stack);
t_stack		*ft_lstncpy(t_stack *stack, long start, long n);
intmax_t	take_elem(t_stack *stack, int n);
t_stack		*ft_sort_list(t_stack *stack);
int			swap_is_sort_a(t_stack *stack, int n);
int			swap_is_sort_b(t_stack *stack, int n);
void		sort_by_pivot_stack_a(t_info_list *info, t_size_list *size_list);
void		sort_by_pivot_stack_b(t_info_list *info, t_size_list *size_list);
t_size_list	*initial_size_list(void);
t_info_list	*initial_info_list(void);
t_stack		*create_stack_list(void);
void		stack_list_added(t_stack *stack, intmax_t data);
void		sort_less_three_stack_a(t_info_list *info, t_size_list *size_list);
void		sort_less_three_stack_b(t_info_list *info, t_size_list *size_list);
void		sort_less_three_stack_reverse_a(t_info_list *info, \
	t_size_list *size_list);
void		sort_less_three_stack_reverse_b(t_info_list *info, \
	t_size_list *size_list);
void		sort_more_three_stack_a(t_info_list *info, t_size_list *size_list);
void		sort_more_three_stack_reverse_a(t_info_list *info, \
	t_size_list *size_list);
void		sort_more_three_stack_b(t_info_list *info, t_size_list *size_list);
void		sort_more_three_stack_reverse_b(t_info_list *info, \
	t_size_list *size_list);
void		sort_by_pivot_stack_reverse_a(t_info_list *info, \
	t_size_list **size_list, int *i, int pivot);
void		sort_by_pivot_stack_reverse_b(t_info_list *info, \
	t_size_list **size_list, int *i, int pivot);
void		sorting_stack_a(t_info_list *info, t_size_list \
	*size_list_next, int pivot, int size);
void		reverse_sorting_stack_a(t_info_list *info, \
	t_size_list *size_list_next, int pivot, int size);
void		sorting_stack_b(t_info_list *info, t_size_list *size_list_next, \
	int pivot, int size);
void		reverse_sorting_stack_b(t_info_list *info, \
	t_size_list *size_list_next, int pivot, int size);
void		sorting_a_one(t_info_list *info);
void		sorting_a_two(t_info_list *info);
void		sorting_b_one(t_info_list *info);
void		sorting_b_two(t_info_list *info);
void		sorting_b_three(t_info_list *info);
void		del(t_info_list *start);
void		dealloc_stack(t_stack *stack);
void		sorting_algorithm_for_stack_a_less_three(t_info_list *info);
void		sorting_algorithm_for_stack_reverse_a_less_three(t_info_list *info);
void		sorting_algorithm_for_stack_reverse_b_add_1(t_info_list *info, \
	int *i, t_size_list *size_list);
void		sorting_algorithm_for_stack_reverse_b_add_2(t_info_list *info, \
	int *i, t_size_list *size_list);
void		sorting_algorithm_for_stack_reverse_b_add_3(t_info_list *info, \
	int *i, t_size_list *size_list);

/*
**			CHECKER
*/

int			ft_printf(const char *format, ...);
int			ft_atoi(const char *str);
int			*ft_arrcpy(int *src, unsigned long n);
int			ps_is_sort(t_info_list *info);
void		ps_pa(t_info_list *info, int print);
void		ps_sa(t_info_list *info, int print);
void		ps_sb(t_info_list *info, int print);
void		ps_pb(t_info_list *info, int print);
void		ps_ss(t_info_list *info, int print);
void		ps_ra(t_info_list *info, int print);
void		ps_rb(t_info_list *info, int print);
void		ps_rr(t_info_list *info, int print);
void		ps_rra(t_info_list *info, int print);
void		ps_rrb(t_info_list *info, int print);
void		ps_rrr(t_info_list *info, int print);
int			get_next_line(const int fd, char **line);
void		print_stack_list(t_info_list *info);
void		choose_command(t_info_list *info, int print, char *line);
int			check_command(char *line);
int			errors_report(int error);
int			parse_digit(char *str);
char		**ft_split(char *line);
void		flags_c_printing(t_info_list *info);
void		flags_v_printing(t_info_list *info);

#endif
