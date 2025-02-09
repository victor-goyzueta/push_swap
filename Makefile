# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 05:13:35 by vgoyzuet          #+#    #+#              #
#    Updated: 2025/02/09 03:32:25 by vgoyzuet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	=	\033[1;32m
CYAN	=	\033[0;36m
WHITE	=	\033[0m
CLEAR	=	\r\033[K

NAME = push_swap
BNS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft

LIBFT = libft/libft.a

SRCS = src/main.c\
	src/init_stack.c\
	src/swap.c\
	src/push.c\
	src/rotate.c\
	src/print_mov.c\
	src/size_short.c\
	src/size_long.c\
	src/worst_case_long.c\
	src/utils.c\
	src/free_utils.c\

BNS_SRCS = src_bonus/main_bonus.c\
	src_bonus/checker_bonus.c\
	src_bonus/swap_bonus.c\
	src_bonus/push_bonus.c\
	src_bonus/rotate_bonus.c\
	src_bonus/utils_bonus.c\


OBJ = $(SRCS:%.c=objs/%.o)

BNS_OBJ = $(BNS_SRCS:%.c=bns_objs/%.o)

all: $(LIBFT) $(NAME)

$(NAME): objs $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)push_swap ready$(WHITE)"
	
$(LIBFT):
	@make --silent -C libft

objs:
	@mkdir -p objs/src/

bns_objs:
	@mkdir -p bns_objs/src_bonus/

objs/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bns_objs/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(LIBFT) $(BNS_NAME)

$(BNS_NAME): bns_objs $(BNS_OBJ)
	@$(CC) $(CFLAGS) $(BNS_OBJ) $(LIBFT) -o $(BNS_NAME)
	@echo "$(GREEN)checker ready$(WHITE)"


clean:
	@make --silent clean -C libft
	@rm -rf objs
	@rm -rf bns_objs
	@echo "Objetcs files deleted."

fclean: clean
	@make --silent fclean -C libft
	@rm -f $(NAME)
	@rm -f $(BNS_NAME)
	@echo "Full clean completed"

re: fclean all

.PHONY: all clean fclean re