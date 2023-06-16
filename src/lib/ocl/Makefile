# Tree
FILE = main
BIN = exec
SRC = $(addprefix ./src/, $(addsuffix .c, $(FILE)))
OBJ = $(addprefix ./obj/, $(addsuffix .o, $(FILE)))

# Compiler
CXX = gcc
INC = ./inc/
LDFLAGS = 
CXXFLAGS = -Werror -Wextra -I $(INC)


$(BIN):	$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

obj/%.o: src/%.c
	$(CXX) $(CXXFLAGS) -c $<

all:	$(BIN)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re