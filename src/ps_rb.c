/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 19:13:11 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/01 19:13:13 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../include/structure.h"
#include "../include/push_swap.h"

void			ps_rb(t_info_list *info, int print)
{
	t_stack		*tmp;
	t_stack		*last;

	if (info->b != NULL)
	{
		tmp = info->b;
		last = info->b;
		if (info->b->next != NULL)
		{
			info->b = info->b->next;
			while (last->next)
				last = last->next;
			tmp->next = NULL;
			last->next = tmp;
		}
		if (print)
			write(1, "rb\n", 3);
	}
}
