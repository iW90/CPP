# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 19:32:32 by inwagner          #+#    #+#              #
#    Updated: 2024/10/12 12:06:42 by inwagner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TITLE
NAME	:=	RPN

# PATHS
SRC		:=	./
HSRC	:=	./
OSRC	:=	./objs/

# FLAGS
FLAGS	:=	-Wall -Wextra -Werror -std=c++98 -I $(HSRC)

# OBJECTS
FTS		:=	main.cpp \
			RPN.cpp

OBJ		:=	$(FTS:%.cpp=$(OSRC)/%.o)

# Compilation
all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(OBJ) -o $@

$(OSRC)/%.o: $(SRC)%.cpp
	@mkdir -p $(@D)
	@c++ $(FLAGS) -c $< -o $@


# exemplos:
## "8 9 * 9 - 9 - 9 - 4 - 1		   +"  		= 42
## "8 9 * 9 - 9 - 9 - 4 - 1 +"				= 42
## "7 7 * 7 -"								= 42
## "1 2 * 2 / 2 * 2 4 - +"					= 0
## "5 1 2 + 4 * + 3 -"						= 14
## "5 1 2 + 4 * +"							= 17
## "5 1 2 + 4 * "							= Incompleto
## "(1 + 1)"								= Inválido
exec: re
	@./${NAME}  "8 9 * 9 - 9 - 9 - 4 - 1		   +" || echo ""

val: re
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} || echo ""

clean:
	@[ -d ./objs ] && rm -rf ./objs || echo ""

fclean: clean
	@[ -f ./$(NAME) ] && rm $(NAME) || echo ""

re: fclean all



.PHONY: all clean fclean re val