# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddias-fe <ddias-fe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 21:05:41 by ddias-fe          #+#    #+#              #
#    Updated: 2025/03/11 17:19:00 by ddias-fe         ###   ########.fr        #
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
SANITIZE = -L. -lpthread -g3 -fsanitize=thread -O3 -march=native
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
		$(SRC_DIR)/executor/exec_utils.c \
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
	$(CC) $(CFLAGS) $(SANITIZE) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@if [ -d $(OBJ_DIR)/inits ]; then $(RMDIR) $(OBJ_DIR)/inits; fi
	@if [ -d $(OBJ_DIR)/parser ]; then $(RMDIR) $(OBJ_DIR)/parser; fi
	@if [ -d $(OBJ_DIR)/utils ]; then $(RMDIR) $(OBJ_DIR)/utils; fi
	@if [ -d $(OBJ_DIR)/executor ]; then $(RMDIR) $(OBJ_DIR)/executor; fi
	@if [ -d $(OBJ_DIR)/free ]; then $(RMDIR) $(OBJ_DIR)/free; fi
	@if [ -d $(OBJ_DIR) ]; then $(RMDIR) $(OBJ_DIR); fi

gdb:
	gdb -tui ./philo

valgrind:
	@valgrind --leak-check=full -s --show-leak-kinds=all ./$(NAME)

helgrind:
	@valgrind --tool=helgrind ./$(NAME)

re: fclean all