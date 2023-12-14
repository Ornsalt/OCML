#########################################
## PROJECT      : C LIBRARIES - OCML   ##
## DATE         : 2023                 ##
## ENVIRONEMENT : Unix                 ##
## DEPENDENCIES : OCL CSFML            ##
## AUTHOR       : ORNSOLOT             ##
#########################################

##################
## Project Tree ##
##################

## Binary file(s)
#################
BDR	= ..
BXT = .a
BIN	= lib$(shell basename $(shell pwd))

## Source file(s)
#################
SDR	= src
SXT	= .c
SRC = $(shell find $(SDR) -name '*$(SXT)' ! -path '*/lib/*')

ODR	= obj
OXT	= .o
OBJ = $(subst $(SXT),$(OXT), $(subst $(SDR),$(ODR),$(SRC)))

## Dependencies file(s)
#######################
LDR	= $(SDR)/lib
IDR = -I $(SDR)/inc -I $(LDR)/*/$(SDR)/inc
ELB = $(shell find $(LDR) -mindepth 1 -maxdepth 1 -not -empty -type d -printf '%f\n' | sort -k 2)
CLN = $(addprefix clean_, $(ELB))
LXT	= .a
LIB	= $(shell find $(LDR) -mindepth 1 -maxdepth 1 -name '*$(LXT)')

## Compiler
CC		= gcc
CCFLAGS	= -g3 -Wall -Wextra -Werror $(IDR)

## Linker
LK		= ar
LKFLAGS	= rcso

#######################
## MAKEFILE VARIABLE ##
#######################
MAKEFLAGS	= --no-print-directory
HEAD		= $(LIFELINE)" ├──"
LEFT		= $(LIFELINE)" │ "
NODE		= $(LIFELINE)" ├── [✓]"
TAIL		= $(LIFELINE)" └── [✓]"

####################
## Makefile Rules ##
####################
.PHONY: re all clean $(BIN)

## General rules
################
re:	clean all

all: $(BIN)

clean: $(CLN)
	@rm -Rf $(ODR)
	@rm -f $(BDR)/$(BIN)$(BXT)
	
vanity:
	@echo "$(LEFT)"
	@echo "$(LEFT)\t ██████╗  ██████╗███╗   ███╗██╗"
	@echo "$(LEFT)\t██╔═══██╗██╔════╝████╗ ████║██║"
	@echo "$(LEFT)\t██║   ██║██║     ██╔████╔██║██║"
	@echo "$(LEFT)\t██║   ██║██║     ██║╚██╔╝██║██║"
	@echo "$(LEFT)\t╚██████╔╝╚██████╗██║ ╚═╝ ██║███████╗"
	@echo "$(LEFT)\t ╚═════╝  ╚═════╝╚═╝     ╚═╝╚══════╝"
	@echo "$(LEFT)"                                      

vanity1:
	@echo "$(LEFT)"
	@echo "$(LEFT)\t ▒█████   ▄████▄   ███▄ ▄███▓ ██▓"
	@echo "$(LEFT)\t▒██▒  ██▒▒██▀ ▀█  ▓██▒▀█▀ ██▒▓██▒"
	@echo "$(LEFT)\t▒██░  ██▒▒▓█    ▄ ▓██    ▓██░▒██░"
	@echo "$(LEFT)\t▒██   ██░▒▓▓▄ ▄██▒▒██    ▒██ ▒██░"
	@echo "$(LEFT)\t░ ████▓▒░▒ ▓███▀ ░▒██▒   ░██▒░██████▒"
	@echo "$(LEFT)\t░ ▒░▒░▒░ ░ ░▒ ▒  ░░ ▒░   ░  ░░ ▒░▓  ░"
	@echo "$(LEFT)\t  ░ ▒ ▒░   ░  ▒   ░  ░      ░░ ░ ▒  ░"
	@echo "$(LEFT)\t░ ░ ░ ▒  ░        ░      ░     ░ ░"
	@echo "$(LEFT)\t░ ░  ░ ░             ░       ░  ░"
	@echo "$(LEFT)\t         ░"
	@echo "$(LEFT)"

## procedural Rules
###################
$(ELB):
	@echo "$(HEAD) $@"
	@make -C $(LDR)/$@ lib$@ LIFELINE='$(LEFT) '
	@echo "$(LEFT)"

$(ODR)/%.o: $(SDR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CCFLAGS) -o $@ -c $<
	@echo "$(NODE) $<"

$(BIN): vanity $(ELB) $(OBJ)
	@$(LK) $(LKFLAGS) $(BDR)/$@$(BXT) $(OBJ) $(LIB)
	@echo "$(TAIL) $(BDR)/$@$(BXT)"

$(CLN):
	@make -C $(LDR)/$(subst clean_,,$@) clean