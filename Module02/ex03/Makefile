NAME = inside_of_triangule
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
SRC = Fixed.cpp main.cpp Point.cpp bsp.cpp
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