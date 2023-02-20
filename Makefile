NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Warrior
SRCS = ft_printf.c
OBJS =	$(SRCS:.c=.o)

all :	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fcean all

.PHONY	all clean fclean re