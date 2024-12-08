# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inwagner <inwagner@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 18:25:59 by inwagner          #+#    #+#              #
#    Updated: 2024/06/11 21:48:49 by inwagner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TITLE
NAME	:=	phonebook

# PATHS
SRC		:=	./
HSRC	:=	./
OSRC	:=	./objs/

# FLAGS
FLAGS	:=	-Wall -Wextra -Werror -std=c++98 -I $(HSRC)

# OBJECTS
FTS		:=	main.cpp \
			Contact.cpp \
			PhoneBook.cpp
			
OBJ		:=	$(FTS:%.cpp=$(OSRC)/%.o)

# Compilation
all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(OBJ) -o $@

$(OSRC)/%.o: $(SRC)%.cpp
	@mkdir -p $(@D)
	@c++ $(FLAGS) -c $< -o $@

val: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME} || echo ""

clean:
	@[ -d ./objs ] && rm -rf ./objs || echo ""

fclean: clean
	@[ -f ./$(NAME) ] && rm $(NAME) || echo ""

re: fclean all



.PHONY: all clean fclean re val