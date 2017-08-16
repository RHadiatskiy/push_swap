/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 19:13:33 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/01 19:13:37 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/structure.h"
#include "../include/push_swap.h"

void	ps_rr(t_info_list *info, int print)
{
	ps_ra(info, print);
	ps_rb(info, print);
	if (print)
		write(1, "rr\n", 3);
}
