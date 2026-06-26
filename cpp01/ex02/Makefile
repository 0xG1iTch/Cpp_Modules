
CFLAGS = -Wall -Wextra -Werror

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = brain

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.cpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all
