# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 05:13:35 by vgoyzuet          #+#    #+#              #
#    Updated: 2025/01/30 17:33:28 by vgoyzuet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	=	\033[1;32m
CYAN	=	\033[0;36m
WHITE	=	\033[0m
CLEAR	=	\r\033[K

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft

LIBFT = libft/libft.a

SRCS = src/main.c\
	src/swap.c\
	src/push.c\
	src/rotate.c\
	src/push_swap.c\
	src/print_mov.c\
	src/init_stack.c\

OBJ = $(SRCS:%.c=objs/%.o)

all: $(LIBFT) $(NAME)

$(NAME): objs $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)push_swap ready$(WHITE)"
	
$(LIBFT):
	@make --silent -C libft

objs:
	@mkdir -p objs/src/

objs/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make --silent clean -C libft
	@rm -rf objs
	@echo "Objetcs files deleted."

fclean: clean
	@make --silent fclean -C libft
	@rm -f $(NAME)
	@echo "Full clean completed"

re: fclean all

.PHONY: all clean fclean re