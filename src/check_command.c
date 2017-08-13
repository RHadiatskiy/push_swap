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

#include "../include/structure.h"
#include "../include/checker.h"

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
