CPPFILES = main.cpp Fixed.cpp

INC = Fixed.hpp

CPPCOMPILER = c++

NAME = fixed

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(CPPFILES:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS) $(INC)
	$(CPPCOMPILER) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean :
	-@rm -rf $(OBJS)

fclean : clean
	-@rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
