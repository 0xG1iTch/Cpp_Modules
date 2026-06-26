CXX = c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = PmergeMe
INFILES = 	main.cpp PmergeMe.cpp
OBJFILES = $(INFILES:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJFILES)
	$(CXX) $(CXX_FLAGS) $(OBJFILES) -o $(NAME) 

%.o: %.cpp PmergeMe.hpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)
fclean: clean
	rm -f $(NAME)

re: fclean all