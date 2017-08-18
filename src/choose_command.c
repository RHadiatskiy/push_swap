/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 16:37:27 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/11 16:37:29 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/structure.h"
#include "../include/push_swap.h"

void		choose_command(t_info_list *info, int print, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		ps_sa(info, print);
	else if (ft_strcmp(line, "sb") == 0)
		ps_sb(info, print);
	else if (ft_strcmp(line, "ss") == 0)
		ps_ss(info, print);
	else if (ft_strcmp(line, "pa") == 0)
		ps_pa(info, print);
	else if (ft_strcmp(line, "pb") == 0)
		ps_pb(info, print);
	else if (ft_strcmp(line, "ra") == 0)
		ps_ra(info, print);
	else if (ft_strcmp(line, "rb") == 0)
		ps_rb(info, print);
	else if (ft_strcmp(line, "rr") == 0)
		ps_rr(info, print);
	else if (ft_strcmp(line, "rra") == 0)
		ps_rra(info, print);
	else if (ft_strcmp(line, "rrb") == 0)
		ps_rrb(info, print);
	else if (ft_strcmp(line, "rrr") == 0)
		ps_rrr(info, print);
	free(line);
}
