CPPFILES = main.cpp UnknownStr.cpp

INC = UnknownStr.hpp

CXX = c++

NAME = convert

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(CPPFILES:.cpp=.o)

$(NAME): $(OBJS) $(INC)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	-@rm -rf $(OBJS)
fclean : clean
	-@rm -rf $(NAME)
re : fclean $(NAME)
