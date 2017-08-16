/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:27:20 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/31 18:27:21 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/structure.h"
#include "../include/push_swap.h"

void	ps_sb(t_info_list *info, int print)
{
	int			tmp;

	if (info->b != NULL)
	{
		if (info->b->next)
		{
			tmp = info->b->data;
			info->b->data = info->b->next->data;
			info->b->next->data = tmp;
			if (print)
				write(1, "sb\n", 3);
		}
	}
}
