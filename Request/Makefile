NAME = request
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME) clean
	@./$(NAME)

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $@

clean:
	@rm -rf $(OBJ) && clear

fclean: clean
	@rm -rf $(NAME) && clear

re: fclean all
