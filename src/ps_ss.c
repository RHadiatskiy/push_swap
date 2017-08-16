/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:27:33 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/31 18:27:35 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/structure.h"
#include "../include/push_swap.h"

void	ps_ss(t_info_list *info, int print)
{
	ps_sa(info, print);
	ps_sb(info, print);
	if (print)
		write(1, "ss\n", 3);
}
