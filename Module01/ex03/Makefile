NAME = unnecessaryViolence

CPPFILES = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

CPPCOMPILER = c++

INC = HumanA.hpp HumanB.hpp Weapon.hpp

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

OBJS = $(CPPFILES:.cpp=.o)

$(NAME): $(OBJS) $(INC)
	$(CPPCOMPILER) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean :
	-@rm -rf $(OBJS)

fclean : clean
	-@rm -rf $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
