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

NAME=push_swap
CHCK=checker

CC= gcc -o
CFLAGS= -Wall -Werror -Wextra -g
LIBFT= -L ./libft/ -lft
PUSH= ./src/push_swap.c
CHECK= ./src/checker.c
LIBFTPRINTF= ./src/ft_printf/libftprintf.a

SRC= ./src/check_command.c ./src/choose_command.c \
		./src/errors_report.c ./src/ft_list_func.c \
		./src/ft_split.c ./src/initial_creating_lists.c \
		./src/parse_digits.c ./src/ps_is_sort.c \
		./src/ps_pa.c ./src/ps_pb.c ./src/ps_ra.c \
		./src/ps_rb.c ./src/ps_rr.c ./src/ps_rra.c \
		./src/ps_rrb.c ./src/ps_rrr.c ./src/ps_sa.c \
		./src/ps_sb.c ./src/ps_ss.c ./src/recursion_stack_a.c \
		./src/recursion_stack_b.c ./src/sorting_more_three_stack_funcs.c \
		./src/take_elem.c ./src/sorting_less_three_stack_func.c \
		./src/sorting_stacks.c ./src/memory_free.c \
		./src/addition_functions_for_sorting.c \
		./src/printing_flags.c

all: $(NAME)

$(NAME):
	@make -C libft
	@make -C ./src/ft_printf
	@$(CC) $(NAME) $(CFLAGS) $(PUSH) $(SRC) $(LIBFT) $(LIBFTPRINTF)
	@$(CC) $(CHCK) $(CFLAGS) $(CHECK) $(SRC) $(LIBFT) $(LIBFTPRINTF)

clean:
	@make -C libft fclean
	@make -C ./src/ft_printf fclean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(CHCK)

re: fclean all
