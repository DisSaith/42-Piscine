CC 		= cc
CFLAGS 		= -Wall -Wextra -Werror -I includes
NAME 		= rush-02

SRCS 		= srcs/main.c srcs/is_ascii.c srcs/convert.c srcs/dictionary.c srcs/parsing.c srcs/useful.c
OBJS 		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

.PHONY:		all clean fclean
