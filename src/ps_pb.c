/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:27:02 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/31 18:27:04 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/structure.h"
#include "../include/push_swap.h"

void	ps_pb(t_info_list *info, int print)
{
	t_stack		*tmp;

	if (info->a != NULL)
	{
		tmp = info->a;
		if (info->a->next != NULL)
			info->a = info->a->next;
		else
			info->a = NULL;
		if (info->b != NULL)
			tmp->next = info->b;
		else
			tmp->next = NULL;
		info->b = tmp;
		if (print)
			write(1, "pb\n", 3);
	}
}
