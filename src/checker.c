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

#include "../include/push_swap.h"

void		check_parse_flags(char **av, int *i, t_info_list *info)
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
			check_parse_flags(av, i, info);
		else
			return (errors_report(1));
	}
	return (0);
}

int			reading_command(char *line, t_info_list *info)
{
	if (info->flag_v == 1)
		flags_v_printing(info);
	while (get_next_line(0, &line))
	{
		if (!check_command(line))
			return (0);
		if (!ft_strcmp(line, "\0"))
			break ;
		if (info->flag_v == 0)
		{
			choose_command(info, 0, line);
			info->i++;
		}
		else
		{
			info->i++;
			choose_command(info, 1, line);
			flags_v_printing(info);
		}
	}
	if (info->flag_v == 1)
		ft_printf("\n%sTOTAL :%s \t%s%jd%s\n", \
			WHITE, RESET, YELLOW, info->i, RESET);
	return (1);
}

int			main(int argc, char **argv)
{
	int				i;
	t_info_list		*info;
	char			*line;

	i = 1;
	line = NULL;
	if (!argv[1])
		return (errors_report(1));
	info = initial_info_list();
	if ((parse_and_fill_list(argc, argv, &i, info)) == 1)
		return (0);
	if (!reading_command(line, info))
		return (errors_report(1));
	if (info->flag_c == 1)
		flags_c_printing(info);
	ps_is_sort(info);
	del(info);
	return (0);
}
