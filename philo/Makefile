# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 21:05:41 by ddias-fe          #+#    #+#              #
#    Updated: 2024/09/30 17:28:19 by ddias-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# _______________________________________________________________
#|___________________________[VARIABLES]_________________________|
#|_______________________________________________________________|

NAME = philo
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
		$(SRC_DIR)/inits/init_data.c \
		$(SRC_DIR)/parser/parser.c \
		$(SRC_DIR)/utils/utils.c \
		$(SRC_DIR)/executor/exec.c \
		$(SRC_DIR)/free/free_program.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# _______________________________________________________________
#|_____________________________[RULES]___________________________|
#|_______________________________________________________________|

all: deps $(NAME)

deps:

#	CREATE OBJECTS FOLDER
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/inits
	@mkdir -p $(OBJ_DIR)/parser
	@mkdir -p $(OBJ_DIR)/utils
	@mkdir -p $(OBJ_DIR)/executor
	@mkdir -p $(OBJ_DIR)/free
	@echo "Created object directories."

$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@$(RMDIR) $(OBJ_DIR)/inits $(OBJ_DIR)/parser $(OBJ_DIR)/utils $(OBJ_DIR)/executor $(OBJ_DIR)/free
	@$(RMDIR) $(OBJ_DIR)

gdb:
	gdb -tui ./philo

valgrind:
	@valgrind --leak-check=full --tool=helgrind -s --show-leak-kinds=all ./$(NAME)

re: fclean all