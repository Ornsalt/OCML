#########################################
## PROJECT      : C LIBRARIES - OCML   ##
## DATE         : 2023                 ##
## ENVIRONEMENT : Unix                 ##
## DEPENDENCIES : OCML OCL CSFML       ##
## AUTHOR       : ORNSOLOT             ##
#########################################

# Project Tree
BINDIR	= .
BINEXT	= .exe
OBJDIR	= obj
OBJEXT	= .o
SRCDIR	= src
SRCEXT	= .c
INCDIR	= $(SRCDIR)/inc/
LIBDIR	= $(SRCDIR)/lib/

# compilation
BIN	= projectname$(BINEXT)

CC	= gcc
CCFLAGS	= -g3 -Wall -Wextra -Werror -I./$(INCDIR)

LK	= gcc
LDLAGS	= -L./$(LIBDIR) $(LIB)

# Variable
DEP	:= csfml-graphics csfml-system csfml-window csfml-audio
SRC	:= $(wildcard $(SRCDIR)/*.c)
INC	:= $(wildcard $(INCDIR)/*.h)
OBJ	:= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
LIB	:= $(addprefix -l, $(DEP))

# Rules
.PHONY: fclean clean

$(BIN): $(OBJ)
	$(CC) -o $@ $< $(CFLAGS) $(LDLAGS)
	@echo "Linking complete!"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -c $(CFLAGS) -o $@ $<
	@echo "[✓] $<"

clean:
	rm -f $(OBJ)
	@echo "Cleanup complete!"


fclean: clean
	rm -f $(BINDIR)/$(BIN)
	@echo "Executable removed!"