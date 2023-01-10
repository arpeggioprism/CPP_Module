CPPFILES = Account.cpp tests.cpp

OBJS = $(CPPFILES:.cpp=.o)

CC = c++

CPPFLAGS = -Wall -Wextra -std=c++98

NAME = bank

$(NAME) : $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $@

clean :
	-@rm -rf $(OBJS)

fclean : clean
	-@rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
