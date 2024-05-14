NAME = blackjack.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = \
	   srcs/blackjack.c \
	   srcs/ft_input.c \
	   srcs/deck.c \
	   srcs/players.c \
	   srcs/libft/ft_strncmp.c \
	   srcs/libft/ft_atoi.c \
	   srcs/libft/ft_isdigit.c \
	   srcs/libft/ft_itoa.c \
	   srcs/libft/ft_strlen.c \
	   srcs/libft/ft_strdup.c

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		   ar -rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

REMEMBER = $(pkg-config --cflags --libs readline)
