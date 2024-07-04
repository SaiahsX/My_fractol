# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 16:05:10 by oadewumi          #+#    #+#              #
#    Updated: 2024/07/04 21:44:51 by oadewumi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBMLX = ./MLX42
LIBFT_DIR = ./libft

SOURCES = fractol.c \
			security_utilities.c \
			garage_files.c \
			fract_files.c \
			mlx_utilities.c \
			utilities.c
OFILES = $(SOURCES:.c=.o)

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -Ofast -I $(LIBFT_DIR) -I ./include -I $(LIBMLX)/include
LDFLAGS = -L $(LIBMLX)/build
LIBS = -lmlx42 -ldl -lglfw -pthread -lm
LIBFT = $(LIBFT_DIR)/libft.a

# MLX42
REPO_URL=https://github.com/codam-coding-college/MLX42.git
REPO_DIR=MLX42

all: clone libmlx $(NAME)

clone:
	@if [ ! -d "$(REPO_DIR)" ]; then \
		git clone $(REPO_URL); \
	else \
		echo "$(REPO_DIR) already exists."; \
	fi

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(LIBFT) $(OFILES)
	$(CC) $(OFILES) $(LIBFT) $(LDFLAGS) $(LIBS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

norm:
	norminette -R CheckForbiddenSourceHeader $(SOURCES)

debug: CFLAGS += -g -fsanitize=address -Ofast
debug: re

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OFILES) 
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(LIBMLX)/build

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re norm libmlx debug clone
