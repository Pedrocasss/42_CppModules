NAME = phonebook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp \
		Contact.cpp
OBJ =  $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all