/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 19:13:48 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/01 19:13:50 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../include/structure.h"
#include "../include/push_swap.h"

void			ps_rra(t_info_list *info, int print)
{
	t_stack		*tmp;
	t_stack		*last;

	last = info->a;
	if (info->a != NULL)
	{
		if (info->a->next != NULL)
		{
			while (last->next->next)
				last = last->next;
			tmp = last->next;
			last->next = NULL;
			tmp->next = info->a;
			info->a = tmp;
		}
		if (print)
			write(1, "rra\n", 4);
	}
}
