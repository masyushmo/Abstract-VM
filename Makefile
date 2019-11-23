# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 16:44:14 by mmasyush          #+#    #+#              #
#    Updated: 2019/11/23 15:04:33 by mmasyush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang++ -std=c++11

FLAGS = -Wall -Werror -Wextra

NAME = avm 

SRC = Parser.cpp Lexer.cpp main.cpp Exept.cpp

HEAD = Parser.hpp Lexer.hpp Exept.hpp IOperand.hpp

HEAD_DIR = $(addprefix $(./headers/), $(HEAD)) 

SRC_DIR = ./src/

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all: obj_dir $(NAME)
	@echo "\033[22;32mCOMPILATED! \033[22;35mヽ(•‿•)ノ"

obj_dir:
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp $(HEADERS)
	$(CC) $(FLAGS) -o $@ -c $< 

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
