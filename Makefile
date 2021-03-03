CC=gcc
CFLAGS=-Wall -Wextra -Werror
EXEC=libftprintf.a
SRC= ft_printf.c \
	convert.c \
	tools.c \
	precisions.c\
	tools_precisions.c\
	write_precisions.c\

OBJ= $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)


.PHONY: clean fclean re test

libftprintf.a: $(OBJ)
	ar -rcs $@ $(OBJ)

clean:
	rm -rf *.o test

fclean: clean
	rm -rf $(EXEC)

re: fclean all

test: $(EXEC) main.o
	gcc -o test main.o -L. -lftprintf
	./test | cat -e

debug: CFLAGS += -g
debug: test
