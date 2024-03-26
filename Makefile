CC = gcc
MAIN = $(ARGS)
CFILES = $(wildcard *.c)
SRC = $(filter-out main.c, $(CFILES))
SRC := $(filter-out %-main.c, $(SRC))
OBJ = $(SRC:%.c=%.o)
NAME = build/main
CFLAGS = -Wall -Werror -Wextra -pedantic

.PHONY: all clean oclean fclean re

all: $(OBJ)
	$(CC) $(OBJ) $(MAIN) -o $(NAME)

clean:
	$(RM) *~ $(NAME)

oclean:
	$(RM) $(OBJ)

fclean: clean oclean

re: fclean all
