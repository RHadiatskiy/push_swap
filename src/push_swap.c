/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 19:22:31 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/01 19:22:35 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../include/push_swap.h"

void		delete_info_list(t_info_list *info)
{
	t_stack		*a_temp;
	t_stack		*b_temp;

	if (info->a)
	{
		while (info->a)
		{
			a_temp = info->a;
			info->a = info->a->next;
			free(a_temp);
		}
	}
	if (info->b)
	{
		while (info->b)
		{
			b_temp = info->b;
			info->b = info->b->next;
			free(b_temp);
		}
	}
	free(info->a);
	free(info->b);
	free(info);
}

int			main(int argc, char **argv)
{
	int				i;
	t_info_list		*info;
	t_size_list		*size_list;

	i = 1;
	info = initial_info_list();
	size_list = initial_size_list();
	if (!argv[1])
		return (errors_report(1));
	while (argc > i)
	{
		if (!parse_digit(argv[i]))
			return (errors_report(2));
		stack_list_added(info->a, ft_atoi(argv[i++]));
	}
	size_list->a_size = ft_list_size(info->a);

	sort_by_pivot_stack_a(info, size_list);

	// print_stack_list(info);
	// printf("size : %d\n", ft_list_size(info->b));
	
	delete_info_list(info);
	free(size_list);
	return (0);
}
