/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:15:35 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/22 17:18:58 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <stdint.h>
# include <stdlib.h>

typedef struct		s_stack
{
	intmax_t			data;
	int					n;
	struct s_stack		*next;
}					t_stack;

typedef struct		s_info_list
{
	t_stack			*a;
	t_stack			*b;
	unsigned int	flag_v : 1;
	unsigned int	flag_c : 1;
	size_t			i;
}					t_info_list;

typedef struct		s_size_list
{
	long			a_size;
	long			b_size;
	int				position_a;
	int				position_b;
}					t_size_list;

#endif
