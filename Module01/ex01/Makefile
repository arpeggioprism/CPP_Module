NAME = moarBrainz!

SRCS = Zombie.cpp main.cpp zombieHorde.cpp

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CPPCOMPILER = c++

OBJS = $(SRCS:.cpp=.o)

all : $(NAME) 

$(NAME) : $(OBJS)
	$(CPPCOMPILER) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean :
	-@rm -f $(OBJS)

fclean : clean
	-@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
