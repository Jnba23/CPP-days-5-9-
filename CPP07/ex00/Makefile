CC = c++
FLAGS = -Wall -Werror -Wextra -Iincs -std=c++98 -MMD -g3
SRC = main.cpp 
HEADER = header.hpp
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:%.cpp=%.o))
DEPSDIR = deps
DEPS = $(addprefix $(DEPSDIR)/, $(SRC:%.cpp=%.d))
EXEC = exec

all: $(EXEC)
# @if [ -f $(EXEC) ]; then ./$(EXEC); else echo "Error $(EXEC) not found"; exit 1; fi
$(EXEC): $(OBJ)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(OBJDIR) $(DEPSDIR)
	$(CC) $(FLAGS) -c $< -o $@ -MF $(DEPSDIR)/$(<:%.cpp=%.d)
# $(OBJDIR)/%.o: %.cpp
# 	@mkdir -p $(OBJDIR) $(DEPSDIR)
# 	$(CC) $(FLAGS) -c $< -o $@
# 	@mv $(OBJDIR)/$(<:.cpp=.d) $(DEPSDIR)/
clean:
	@rm -rf $(OBJDIR) $(DEPSDIR) \
	$$(ls | grep _shrubbery)

fclean: clean
	@rm -rf $(EXEC)

re: fclean all

-include $(DEPS)