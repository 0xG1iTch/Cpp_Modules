CXX = c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = btc
INFILES = 	main.cpp BitcoinExchange.cpp
OBJFILES = $(INFILES:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJFILES)
	$(CXX) $(CXX_FLAGS) $(OBJFILES) -o $(NAME) 

%.o: %.cpp BitcoinExchange.hpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)
fclean: clean
	rm -f $(NAME)

re: fclean all