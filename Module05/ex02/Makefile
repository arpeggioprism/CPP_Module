NAME = a.out

SRCS = main.cpp \
	Bureaucrat.cpp \
	Form.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp \

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean: 
	rm -f $(OBJS)
	rm -f tree_shrubbery

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
