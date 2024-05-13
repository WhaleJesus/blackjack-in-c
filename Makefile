NAME = Blackjack.a
SRCS = \
	   srcs/blackjack.c \
	   srcs/ft_input.c

OBJECTS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
		   ar -rcs $@ $?
%.o: %.c
	$(CC) -c $(CFLAGS) $? srcs/

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re: fclean all
