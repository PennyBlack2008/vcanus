SRCS	=	main.c

OBJS	=	main.o

NAME	=	Factorial

CC		=	gcc

CFLAG	=	-Wall -Wextra -Werror

RM		=	-rm -rf

all		:	$(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAG) -c $(SRCS)
			$(CC) $(CFLAG) -o $(NAME) $(OBJS)

.PHONY	:	all clean fclean re