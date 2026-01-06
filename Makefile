# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amamun <amamun@student.42warsaw.pl>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/04 19:30:00 by amamun            #+#    #+#              #
#    Updated: 2026/01/06 19:45:49 by amamun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= gcc
CFLAGS		=-Wall -Wextra -Werror -I.
RM			= rm -f

# Source files
SRCS		= main.c \
			  error_check.c \
			  libft/ft_split.c \
			  Stack/init_stack.c \
			  Stack/stack_utils.c \
			  Stack/stack_utils_2.c \
			  Sort/init_nodes_a.c \
			  Sort/init_nodes_b.c \
			  Sort/move.c \
			  Sort/sort_stack.c \
			  Sort/tiny_sort.c \
			  Operations/push.c \
			  Operations/swap.c \
			  Operations/rotate.c \
			  Operations/rev_rotate.c

# Object files
OBJS		= $(SRCS:.c=.o)

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

.PHONY: all re clean fclean
