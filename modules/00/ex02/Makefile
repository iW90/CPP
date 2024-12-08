# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 16:33:11 by inwagner          #+#    #+#              #
#    Updated: 2024/06/22 11:13:42 by inwagner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TITLE
NAME	:=	GlobalBankstersUnited

# PATHS
SRC		:=	./
HSRC	:=	./
OSRC	:=	./objs/

# FLAGS
FLAGS	:=	-Wall -Wextra -Werror -std=c++98 -I $(HSRC)

# OBJECTS
FTS		:=	tests.cpp \
			Account.cpp
			
OBJ		:=	$(FTS:%.cpp=$(OSRC)/%.o)

# Compilation
all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(OBJ) -o $@

$(OSRC)/%.o: $(SRC)%.cpp
	@mkdir -p $(@D)
	@c++ $(FLAGS) -c $< -o $@

val: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME}

clean:
	@[ -d ./objs ] && rm -rf ./objs

fclean: clean
	@[ -f ./$(NAME) ] && rm $(NAME)

re: fclean all



.PHONY: all clean fclean re val