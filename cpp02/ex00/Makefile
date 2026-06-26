NAME = ex00
FLAGS = -Wall -Wextra -Werror

SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	g++ $(FLAGS) -o $@ $(OBJS)

%.o: %.cpp Fixed.hpp
	g++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
