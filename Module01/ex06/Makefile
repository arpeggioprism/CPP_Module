CPPFILES = main.cpp Harl.cpp

CPPCOMPILER = c++

INC = Harl.hpp

NAME = harlFilter

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

.PHONY: all clean fclean re
