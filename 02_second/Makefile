SRCS	=	$(wildcard *.cpp)

OBJS	=	$(SRCS:.cpp=.o)

NAME	=	Calculator

CC		=	clang++

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