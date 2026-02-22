CC 		= cc
CFLAGS 		= -Wall -Wextra -Werror
NAME		= ft_tail

SRCS 		= srcs/main.c srcs/utils.c
OBJS		= $(SRCS:.c=.o)

.c.o:
		${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
