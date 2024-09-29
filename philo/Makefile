# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 21:05:41 by ddias-fe          #+#    #+#              #
#    Updated: 2024/01/23 21:05:41 by ddias-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# _______________________________________________________________
#|___________________________[VARIABLES]_________________________|
#|_______________________________________________________________|

NAME = push_swap
LIBFT = ../libs/libft/libft.a
SRC_DIR = ./src
OBJ_DIR = ./obj

#COMPILE/RULE TOOLS
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./include
RM = rm -f
RMDIR = rmdir

# _______________________________________________________________
#|___________________________[SRC FILES]_________________________|
#|_______________________________________________________________|

SRC =	$(SRC_DIR)/main.c \

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# _______________________________________________________________
#|_____________________________[RULES]___________________________|
#|_______________________________________________________________|

all: deps $(NAME)

deps:
#	COMPILE LIBFT LIBRARY
	$(MAKE) -C ./libs/libft

#	CREATE OBJECTS FOLDER
	@mkdir -p $(OBJ_DIR)/algorithm \
		$(OBJ_DIR)/operations \
		$(OBJ_DIR)/parser \
		$(OBJ_DIR)/utils
	@echo "Created object directories."

$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(MAKE) clean -C ./libs/libft
	$(RM) $(OBJ)

fclean: clean
	@$(RM) $(LIBFT) $(NAME)
	@$(RMDIR) $(OBJ_DIR)/algorithm \
			$(OBJ_DIR)/operations \
			$(OBJ_DIR)/parser \
			$(OBJ_DIR)/utils \
			$(OBJ_DIR)

gdb:
	gdb -tui ./push_swap

re: fclean all