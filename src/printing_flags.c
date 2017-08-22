/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 21:15:12 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/22 21:15:14 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		flags_v_printing(t_info_list *info)
{
	ft_printf("\n%sSTEP : \t%d%s", YELLOW, info->i, RESET);
	print_stack_list(info);
	ft_printf("%sSize Stack A :%s \t%s%d%s\n", WHITE, RESET, GREEN, \
		ft_list_size(info->a), RESET);
	ft_printf("%sSize Stack B :%s \t%s%d%s\n", WHITE, RESET, RED, \
		ft_list_size(info->b), RESET);
	write(1, "\n", 1);
}

void		flags_c_printing(t_info_list *info)
{
	print_stack_list(info);
	ft_printf("%sSize Stack A :%s \t%s%d%s\n", WHITE, RESET, GREEN, \
		ft_list_size(info->a), RESET);
	ft_printf("%sSize Stack B :%s \t%s%d%s\n", WHITE, RESET, RED, \
		ft_list_size(info->b), RESET);
	ft_printf("\n%sTOTAL :%s \t%s%jd%s\n", WHITE, RESET, RED, info->i, RESET);
}
