CFLAGS = -Wall -Wextra -Werror

SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = harl_complaints

all: $(EXEC)

$(EXEC): $(OBJ)
	c++ $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.cpp Harl.hpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all
