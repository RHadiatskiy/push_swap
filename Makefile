# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/22 18:51:19 by rhadiats          #+#    #+#              #
#    Updated: 2017/08/13 15:21:32 by bsemchuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS=push_swap
NAME_CHCK=checker

CC= gcc -o
CFLAGS= -Wall -Werror -Wextra -g
LIBFT= libft/libft.a
PUSH= ./src/push_swap
CHECK= ./src/checker
LIBFTPRINTF= ./src/ft_printf/libftprintf.a

SRC= ./src/check_command ./src/choose_command \
		./src/errors_report ./src/ft_list_func \
		./src/ft_split ./src/initial_creating_lists \
		./src/parse_digits ./src/ps_is_sort \
		./src/ps_pa ./src/ps_pb ./src/ps_ra \
		./src/ps_rb ./src/ps_rr ./src/ps_rra \
		./src/ps_rrb ./src/ps_rrr ./src/ps_sa \
		./src/ps_sb ./src/ps_ss ./src/recursion_stack_a \
		./src/recursion_stack_b ./src/sorting_more_three_stack_funcs \
		./src/take_elem ./src/sorting_less_three_stack_func \
		./src/sorting_stacks ./src/memory_free \
		./src/addition_functions_for_sorting \
		./src/printing_flags

OBJ = $(addsuffix .o,$(SRC))
MAIN_PS = $(addsuffix .o,$(PUSH))
MAIN_CHCK = $(addsuffix .o,$(CHECK))

all: lib ft_printf push_swap checker

lib:
	@make -C libft

ft_printf:
	@make -C ./src/ft_printf

push_swap: $(OBJ) $(MAIN_PS)
	@$(CC) $(NAME_PS) $(CFLAGS) $(MAIN_PS) $(OBJ) $(LIBFT) $(LIBFTPRINTF)

checker: $(OBJ) $(MAIN_CHCK)
	@$(CC) $(NAME_CHCK) $(CFLAGS) $(MAIN_CHCK) $(OBJ) $(LIBFT) $(LIBFTPRINTF)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $< 

clean:
	@make -C libft clean
	@make -C ./src/ft_printf clean
	@rm -f $(OBJ)
	@rm -f $(MAIN_PS)
	@rm -f $(MAIN_CHCK)

fclean: clean
	@rm -f $(NAME_PS)
	@rm -f $(NAME_CHCK)
	@rm -f $(LIBFTPRINTF)
	@rm -f $(LIBFT)

re: fclean all
