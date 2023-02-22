NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_pointer_work.c 
OBJS =	$(SRCS:.c=.o)

all :	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fcean all

.PHONY:	all clean fclean re