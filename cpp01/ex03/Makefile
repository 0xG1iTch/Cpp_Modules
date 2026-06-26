FLAGS = -Wall -Wextra -Werror
FILES = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJ = $(FILES:.cpp=.o)

NAME = unnecessary_violence

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Weapon.hpp HumanA.hpp HumanB.hpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
