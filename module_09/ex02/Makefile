# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 19:32:42 by inwagner          #+#    #+#              #
#    Updated: 2024/12/05 20:30:54 by inwagner         ###   ########.fr        #
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
	@./${NAME} `shuf -i 1-100 -n 20 | tr "\n" " "` || echo ""

val: re
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} `shuf -i 1-100000 -n 3000 | tr "\n" " "` || echo ""

clean:
	@[ -d ./objs ] && rm -rf ./objs || echo ""

fclean: clean
	@[ -f ./$(NAME) ] && rm $(NAME) || echo ""

re: fclean all

z:
	c++ $(FLAGS) teste.cpp -o teste
	./teste
	rm teste

.PHONY: all clean fclean re val