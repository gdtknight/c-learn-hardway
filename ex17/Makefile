# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/13 15:53:50 by yoshin            #+#    #+#              #
#    Updated: 2024/10/15 00:23:09 by yoshin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS		=	-Wall -Wextra -Werror -g

NAME		=	cdb

HEADER_DIR	=	includes
SRC_DIR		=	srcs
BUILD_DIR	=	build
BIN_DIR		=	bin
SRCS		=	$(wildcard $(SRC_DIR)/*.c)
OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

.PHONY: all clean fclean re bonus

all:	dirs $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^ -I$(HEADER_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(HEADER_DIR)

dirs:
	mkdir -p ./$(BUILD_DIR)
	mkdir -p ./$(BIN_DIR)

clean: 
	rm -rf  $(BUILD_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all
