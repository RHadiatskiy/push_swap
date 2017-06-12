/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:27:50 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/31 18:27:58 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/structure.h"
#include "../include/checker.h"

void		pasrs_flags(char **av, int *i, t_info_list *info)
{
	if ((ft_strcmp(av[(*i)], "-c")) == 0)
	{
		info->flag_c = 1;
		(*i)++;
	}
	else if ((ft_strcmp(av[(*i)], "-v")) == 0)
	{
		info->flag_v = 1;
		(*i)++;
	}
	else if ((ft_strcmp(av[(*i)], "-cv")) == 0 || \
		(ft_strcmp(av[(*i)], "-vc")) == 0)
	{
		info->flag_c = 1;
		info->flag_v = 1;
		(*i)++;
	}
}

int			parse_and_fill_list(int ac, char **av, int *i, t_info_list *info)
{
	while (ac > (*i))
	{
		if (parse_digit(av[(*i)]))
			stack_list_added(info->a, ft_atoi(av[(*i)++]));
		else if ((ft_strcmp(av[(*i)], "-c")) == 0 || \
			(ft_strcmp(av[(*i)], "-v")) == 0 || \
			(ft_strcmp(av[(*i)], "-cv")) == 0 || \
			(ft_strcmp(av[(*i)], "-vc")) == 0)
			pasrs_flags(av, i, info);
		else
			return (errors_report(1));
	}
	return (0);
}

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
	char			*line;

	i = 1;
	if (!argv[1])
		return (errors_report(1));
	info = initial_info_list();
	if ((parse_and_fill_list(argc, argv, &i, info)) == 1)
		return (0);
	while (get_next_line(0, &line))
	{
		choose_command(info, 0, line);
		if (!check_command(line))
			return (errors_report(1));
		if (info->flag_v == 1)
			print_stack_list(info);
	}
	if (info->flag_c == 1)
		print_stack_list(info);
	ps_is_sort(info);
	delete_info_list(info);
	return (0);
}
