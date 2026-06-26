FLAGS = -Wall -Wextra -Werror
FILES = main.cpp Zombie.cpp zombieHorde.cpp

OBJ = $(FILES:.cpp=.o)

NAME = ZombieHorde

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Zombie.hpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
