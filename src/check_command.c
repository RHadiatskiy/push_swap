/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 16:38:27 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/11 16:38:29 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			check_command(char *line)
{
	int		i;
	int		ret;
	char	*command;
	char	**split;

	i = 0;
	ret = 0;
	command = "sa sb ss pa pb ra rb rr rra rrb rrr";
	split = ft_split(command);
	while (split[i])
		if (ft_strcmp(split[i++], line) == 0)
		{
			ret = 1;
			break ;
		}
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (ret);
}

int			check_the_same_digit(int ac, char **av)
{
	int				i;
	int				j;

	i = 1;
	if ((ft_strcmp(av[1], "-c") == 0) || (ft_strcmp(av[1], "-v") == 0) || \
		(ft_strcmp(av[1], "-cv") == 0) || (ft_strcmp(av[1], "-vc") == 0))
		i = 2;
	while (ac > i)
	{
		j = i + 1;
		while (ac > j)
			if (ft_atoi(av[i]) == ft_atoi(av[j++]))
				return (0);
		i++;
	}
	return (1);
}
