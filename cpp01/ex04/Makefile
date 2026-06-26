CFLAGS = -Wall -Wextra -Werror

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = sed_is_for_losers

all: $(EXEC)

$(EXEC): $(OBJ)
	c++ $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.cpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all
