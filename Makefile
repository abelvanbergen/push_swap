# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avan-ber <avan-ber@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/19 13:14:02 by avan-ber      #+#    #+#                  #
#    Updated: 2022/04/01 15:40:01 by avan-ber      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

CHECKER_FILES =		srcs/checker.c
PUSH_SWAP_FILES =	srcs/push_swap.c
FILES =				srcs/instructions/instructions.c \
					srcs/instructions/double_instructions.c \
					srcs/solver/small_stacks.c \
					srcs/stack/adjust.c \
					srcs/stack/init.c \
					srcs/stack/utils.c \
					srcs/utils/utils.c \
					srcs/utils/print.c \
					srcs/utils/split.c

all: checker push_swap

checker:
	$(CC) $(CFLAGS) $(FILES) $(CHECKER_FILES) -o checker
push_swap:
	$(CC) $(CFLAGS) $(FILES) $(PUSH_SWAP_FILES) -o push_swap
clean:

fclean: clean
	rm -rf checker push_swap

re: fclean all

.PHONY: all clean fclean re

py: all
	python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
