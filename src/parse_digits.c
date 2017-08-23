/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 12:27:25 by rhadiats          #+#    #+#             */
/*   Updated: 2017/06/02 12:28:50 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			parse_digit(char *str)
{
	int				i;

	i = 0;
	while (str[i])
		if (str[i] == '-' && ft_isdigit(str[i + 1]) && str[i + 1] != '0')
			i++;
		else if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}
