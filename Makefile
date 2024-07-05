# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 16:05:10 by oadewumi          #+#    #+#              #
#    Updated: 2024/07/05 18:49:16 by oadewumi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBMLX = ./MLX42
LIBFT_DIR = ./libft

SOURCES = fractol.c \
			security_utilities.c \
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

# Color codes
RED            =   \033[0;31m
GREEN          =   \033[0;32m
YELLOW         =   \033[0;33m
BLUE           =   \033[0;34m
MAGENTA        =   \033[0;35m
CYAN           =   \033[0;36m
RESET          =   \033[0m

# MLX42
REPO_URL=https://github.com/codam-coding-college/MLX42.git
REPO_DIR=MLX42

all: norm libmlx $(NAME)

clone:
	@if [ ! -d "$(REPO_DIR)" ]; then \
		echo "$(YELLOW)Cloning MLX42 library from Codam42....$(RESET)"; \
		git clone $(REPO_URL); \
	else \
		echo "$(BLUE) MLX42 library already exists.$(RESET)"; \
	fi

libmlx:	clone
	@echo "$(YELLOW)Building MLX42 library...$(RESET)"
	@cmake -S $(LIBMLX) -B $(LIBMLX)/build > /dev/null
	@make -C $(LIBMLX)/build -j4 > /dev/null
	@echo "$(GREEN)MLX42 library built and ready.$(RESET)"

$(NAME): $(LIBFT) $(OFILES)
	@echo "$(YELLOW)Building $(NAME)...$(RESET)"
	@$(CC) $(OFILES) $(LIBFT) $(LDFLAGS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)$(NAME) built successfully.$(RESET)"

$(LIBFT):
	@echo "$(CYAN)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)libft built successfully.$(RESET)"

norm:
	@echo "$(YELLOW)Running norminette...$(RESET)"
	@find . -name "*.c" -not -path "./MLX42/*" -print | xargs norminette -R CheckForbiddenSourceHeader
	@find . -name "*.h" -not -path "./MLX42/*" -print | xargs norminette -R CheckForbiddenSourceHeader
	@echo "$(BLUE)Norminette check completed.$(RESET)"

debug: CFLAGS += -g -fsanitize=address -Ofast
debug: re

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiled $< successfully.$(RESET)"

clean:
	@echo "$(RED)Cleaning up...$(RESET)"
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OFILES) 
	@$(RM) $(LIBMLX)/build
	@echo "$(GREEN)Cleanup completed.$(RESET)"

fclean: clean
	@echo "$(RED)Force cleaning...$(RESET)"
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(REPO_DIR)
	@echo "$(GREEN)Full cleanup completed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re norm libmlx debug clone
