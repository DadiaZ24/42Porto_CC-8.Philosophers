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
LIBFT = libs/libft/libft.a
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
		$(SRC_DIR)/parser/args_parser.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# _______________________________________________________________
#|_____________________________[RULES]___________________________|
#|_______________________________________________________________|

all: deps $(NAME)

deps:
#	COMPILE LIBFT LIBRARY
	$(MAKE) -C ./libs/libft

#	CREATE OBJECTS FOLDER
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/inits
	@mkdir -p $(OBJ_DIR)/parser
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
	@$(RMDIR) $(OBJ_DIR)

gdb:
	gdb -tui ./push_swap

re: fclean all