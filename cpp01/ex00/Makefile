FLAGS = -Wall -Wextra -Werror
FILES = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJ = $(FILES:.cpp=.o)

NAME = Zombie

all: $(NAME)

$(NAME):$(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME) 

%.o: %.cpp Zombie.hpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all