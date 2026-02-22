CC 		= cc
CFLAGS 		= -Wall -Wextra -Werror
NAME		= do-op

SRCS 		= srcs/do-op.c srcs/fonctions.c srcs/operators.c
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
