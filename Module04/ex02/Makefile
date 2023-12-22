NAME = AAnimal
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
SRC = WrongAnimal.cpp main.cpp WrongCat.cpp Cat.cpp Dog.cpp AAnimal.cpp Brain.cpp
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