#########################################
## PROJECT      : C LIBRARIES - OCML   ##
## DATE         : 2023                 ##
## ENVIRONEMENT : Unix                 ##
## DEPENDENCIES : OCL CSFML            ##
## AUTHOR       : ORNSOLOT             ##
#########################################

# Binary file
BDR		= ..
BXT 	= .a
BIN		= lib$(shell basename $(shell pwd))

# Source file
SDR		= ./src
SXT		= .c
SRC 	= $(shell find $(SDR) -name '*$(SXT)')

ODR		= ./obj
OXT		= .o
OBJ 	= $(subst $(SXT),$(OXT), $(subst $(SDR),$(ODR),$(SRC)))

IDR 	= -I $(SDR)/inc -I ../ocl/src/inc

# Compiler
CC		= gcc
CCFLAGS	= -g3 -Wall -Wextra -Werror $(IDR)

LK		= ar rcs
LKFLAGS	=

#######################
## MAKEFILE VARIABLE ##
#######################
MAKEFLAGS	+= --no-print-directory

# Rules
$(BIN): $(OBJ)
	@$(LK) $(LKFLAGS) $(BDR)/$@$(BXT) $(OBJ)
	@echo " └─ [✓] $(BDR)/$@$(BXT)"

$(ODR)/%.o: $(SDR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CCFLAGS) -o $@ -c $<
	@echo " ├─ [✓] $<"

all: $(BIN)

clean:
	@rm -Rf $(ODR)

purge: clean
	@rm -f $(BDR)/$(BIN)$(BXT)

re:	purge all

.PHONY: re all clean purge