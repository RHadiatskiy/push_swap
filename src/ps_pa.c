/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:26:39 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/31 18:26:40 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../include/structure.h"
#include "../include/push_swap.h"

void	ps_pa(t_info_list *info, int print)
{
	t_stack		*tmp;

	if (info->b != NULL)
	{
		tmp = info->b;
		if (info->b->next != NULL)
			info->b = info->b->next;
		else
			info->b = NULL;
		if (info->a != NULL)
			tmp->next = info->a;
		else
			tmp->next = NULL;
		info->a = tmp;
		if (print)
			write(1, "pa\n", 3);
	}
}
