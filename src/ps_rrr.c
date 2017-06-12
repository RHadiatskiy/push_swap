/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 19:14:09 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/01 19:14:11 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../include/structure.h"
#include "../include/push_swap.h"

void			ps_rrr(t_info_list *info, int print)
{
	ps_rra(info, print);
	ps_rrb(info, print);
	if (print)
		write(1, "rrr\n", 4);
}
