/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 15:46:57 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/11 15:46:59 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/structure.h"
#include "../include/push_swap.h"

intmax_t	take_elem(t_stack *stack, int n)
{
	int				i;

	i = 0;
	while (stack && i < n)
	{
		stack = stack->next;
		i++;
	}
	return (stack->data);
}
