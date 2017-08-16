/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:17:31 by rhadiats          #+#    #+#             */
/*   Updated: 2017/05/22 17:19:31 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/*
** Colorize an output of printf
*/

# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define YELLOW		"\033[1;33m"
# define WHITE		"\033[1;37m"
# define GREEN		"\033[1;32m"

/*
** ----------------------------
*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

# include "structure.h"
# include "../libft/libft.h"

int			ft_printf(const char *format, ...);
int			ft_atoi(const char *str);
int			ft_list_size(t_stack *stack);
int			*ft_arrcpy(int *src, unsigned long n);
int			ps_is_sort(t_info_list *info);
void		ps_pa(t_info_list *info, int print);
void		ps_sa(t_info_list *info, int print);
void		ps_sb(t_info_list *info, int print);
void		ps_pb(t_info_list *info, int print);
void		ps_ss(t_info_list *info, int print);
void		ps_ra(t_info_list *info, int print);
void		ps_rb(t_info_list *info, int print);
void		ps_rr(t_info_list *info, int print);
void		ps_rra(t_info_list *info, int print);
void		ps_rrb(t_info_list *info, int print);
void		ps_rrr(t_info_list *info, int print);
int			get_next_line(const int fd, char **line);
t_stack		*create_stack_list(void);
void		stack_list_added(t_stack *stack, intmax_t data);
void		print_stack_list(t_info_list *info);
void		choose_command(t_info_list *info, int print, char *line);
int			check_command(char *line);
int			errors_report(int error);
int			parse_digit(char *str);
char		**ft_split(char *line);
t_info_list	*initial_info_list(void);
void		del(t_info_list *start);
void		dealloc_stack(t_stack *stack);

#endif
