CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

MAN = 
OBJS = $(MAN:.cpp=.o)
HEADER = 

EXEC = Bureaucrat

all : $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(EXEC)

re : fclean all