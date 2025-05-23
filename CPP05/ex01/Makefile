CC = c++
FLAGS = -Wall -Werror -Wextra -Iincs -std=c++98

MAN = bureaucrat.cpp main.cpp Form.cpp
OBJ = $(SRC:%.cpp=%.o)
HEADER =
EXEC = Form

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(FLAGS) -o $@

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(EXEC)

fclean : clean
	rm -rf $(OBJ)

re : fclean all