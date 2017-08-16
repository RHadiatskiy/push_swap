/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:10:36 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/31 18:10:39 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/structure.h"
#include "../include/push_swap.h"

void	ps_sa(t_info_list *info, int print)
{
	int			tmp;

	if (info->a != NULL)
	{
		if (info->a->next)
		{
			tmp = info->a->data;
			info->a->data = info->a->next->data;
			info->a->next->data = tmp;
			if (print)
				write(1, "sa\n", 3);
		}
	}
}
