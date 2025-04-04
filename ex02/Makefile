NAME	=	PmergeMe
SRCS	=	main.cpp PmergeMe.cpp
OBJS	=	$(SRCS:.cpp=.o)
CC		=	g++
FLAGS	=	-Werror -Wextra	-Wall  -std=c++98
RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(FLAGS) $(OBJS)	-o $(NAME)

clean	:
			$(RM)	$(OBJS)

fclean	:	clean
			$(RM)	$(NAME)

re		:	fclean all