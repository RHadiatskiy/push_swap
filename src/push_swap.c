/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 19:22:31 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/28 14:57:20 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			main(int argc, char **argv)
{
	int				i;
	t_info_list		*info;
	t_size_list		*size_list;

	i = 1;
	info = initial_info_list();
	size_list = initial_size_list();
	if (!argv[1])
		return (0);
	if (!check_the_same_digit(argc, argv))
		return (errors_report(1));
	while (argc > i)
	{
		if (!parse_digit(argv[i]))
			return (errors_report(1));
		stack_list_added(info->a, ft_atoi(argv[i++]));
	}
	size_list->a_size = ft_list_size(info->a);
	if (!swap_is_sort_a(info->a, ft_list_size(info->a)) && \
		ft_list_size(info->b) == 0)
		sort_by_pivot_stack_a(info, size_list);
	del(info);
	free(size_list);
	return (0);
}
