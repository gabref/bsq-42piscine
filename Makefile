NAME 	= bsq
SRC		= $(wildcard src/*.c)
LIB		= $(wildcard lib/*/*.c)
OBJS 	= $(SRC:.c=.o) $(LIB:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM 		= rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: build

build: $(OBJS)
	mkdir -p build
	$(CC) $(CFLAGS) -o build/$(NAME) $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) build/$(NAME)
	$(RM) -r build

re: fclean all

run:
	./build/$(NAME) ./perl/map_12_13_4

.PHONY: all build clean fclean
