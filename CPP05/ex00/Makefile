CC = c++
FLAGS = -Wall -Werror -Wextra -I. -std=c++98

MAN = Bureaucrat.cpp main.cpp
OBJS = $(MAN:.cpp=.o)
HEADER = Bureaucrat.hpp

EXEC = Bureaucrat

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

%.o : %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(EXEC)

re : fclean all