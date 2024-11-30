# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 19:32:42 by inwagner          #+#    #+#              #
#    Updated: 2024/11/29 22:25:22 by inwagner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TITLE
NAME	:=	PmergeMe

# PATHS
SRC		:=	./
HSRC	:=	./
OSRC	:=	./objs/

# FLAGS
FLAGS	:=	-Wall -Wextra -Werror -std=c++98 -I $(HSRC) -g

# OBJECTS
FTS		:=	main.cpp \
			PmergeMe.cpp

OBJ		:=	$(FTS:%.cpp=$(OSRC)/%.o)

# Compilation
all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(OBJ) -o $@

$(OSRC)/%.o: $(SRC)%.cpp
	@mkdir -p $(@D)
	@c++ $(FLAGS) -c $< -o $@

exec: re
	@./${NAME} 11 12 3 7 9 5 1 13 10 4 6 2 8 || echo ""

val: re
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} 11 12 3 7 9 5 1 13 10 4 6 2 8 || echo ""

clean:
	@[ -d ./objs ] && rm -rf ./objs || echo ""

fclean: clean
	@[ -f ./$(NAME) ] && rm $(NAME) || echo ""

re: fclean all



.PHONY: all clean fclean re val