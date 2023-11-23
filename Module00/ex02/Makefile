# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psoares- <psoares-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 16:01:02 by psoares-          #+#    #+#              #
#    Updated: 2023/11/23 16:01:03 by psoares-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
SRC = Account.cpp tests.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all