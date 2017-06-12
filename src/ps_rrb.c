/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 19:13:59 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/01 19:14:01 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../include/structure.h"
#include "../include/push_swap.h"

void			ps_rrb(t_info_list *info, int print)
{
	t_stack		*tmp;
	t_stack		*last;

	last = info->b;
	if (info->b != NULL)
	{
		if (info->b->next != NULL)
		{
			while (last->next->next)
				last = last->next;
			tmp = last->next;
			last->next = NULL;
			tmp->next = info->b;
			info->b = tmp;
		}
		if (print)
			write(1, "rrb\n", 4);
	}
}
