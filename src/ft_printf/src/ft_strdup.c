/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:01:14 by rhadiats          #+#    #+#             */
/*   Updated: 2017/04/12 21:55:39 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*string;

	i = 0;
	while (str[i] != '\0')
		i++;
	string = (char *)malloc(sizeof(*str) * i + 1);
	if (string == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
