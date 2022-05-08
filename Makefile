# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 18:25:30 by anruland          #+#    #+#              #
#    Updated: 2022/05/08 17:41:28 by anruland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config

NAME 	= so_long
CC 		= gcc
CFLAGS	= -Werror -Wall -Wextra
# Linux
# LIBS	= -ggdb3 -lft -lmlx -lX11 -lXext
# Mac
LIBS	= -ggdb3 -lft -lmlx -framework OpenGL -framework AppKit
LIB_DIR	= -L./libft/ -L./mlx/

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

# Files

SRC		= ./*.c

all: $(NAME)

$(NAME): setup
	@echo "$(COM_COLOR)Compiling so_long$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(LIB_DIR) $(LIBS)
	@echo "$(OK_COLOR)Finished - usage: ./$(NAME) $(NO_COLOR)"

setup:
	@echo "$(COM_COLOR)Compiling libft$(NO_COLOR)"
	@$(MAKE) -C ./libft
	@echo "$(COM_COLOR)Compiling mlx$(NO_COLOR)"
	@$(MAKE) -C ./mlx
	@echo "$(OK_COLOR)done$(NO_COLOR)"

clean:
	@echo "$(COM_COLOR)Cleaning Object Files$(NO_COLOR)"
	@/bin/rm -f 

fclean: clean
	@echo "$(COM_COLOR)Cleaning $(NAME)$(NO_COLOR)"
	@/bin/rm -f $(NAME)
	@$(MAKE) -C ./libft fclean

re: fclean all
