CXX      = c++
NAME     = ex03
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS     = MateriaSource.cpp Character.cpp AMateria.cpp Cure.cpp main.cpp Ice.cpp
OBJS     = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp IMateriaSource.hpp Character.hpp AMateria.hpp MateriaSource.hpp ICharacter.hpp Cure.hpp Ice.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


