CXX      = c++
NAME     = ex01
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS     = Animal.cpp Dog.cpp Cat.cpp main.cpp Brain.cpp
OBJS     = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Animal.hpp Dog.hpp Cat.hpp Brain.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all