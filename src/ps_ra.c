/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 19:12:56 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/01 19:12:59 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/structure.h"
#include "../include/push_swap.h"

void			ps_ra(t_info_list *info, int print)
{
	t_stack		*tmp;
	t_stack		*last;

	if (info->a != NULL)
	{
		tmp = info->a;
		last = info->a;
		if (info->a->next != NULL)
		{
			info->a = info->a->next;
			while (last->next)
				last = last->next;
			tmp->next = NULL;
			last->next = tmp;
		}
		if (print)
			write(1, "ra\n", 3);
	}
}
