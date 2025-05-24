CC = c++
FLAGS = -Wall -Werror -Wextra -Iincs -std=c++98 -MMD
SRC = bureaucrat.cpp main.cpp AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp
HEADER = AForm.hpp bureaucrat.hpp ShrubberyCreationForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:%.cpp=%.o))
DEPSDIR = deps
DEPS = $(addprefix $(DEPSDIR)/, $(SRC:%.cpp=%.d))
EXEC = Form

all: $(EXEC)
	@if [ -f $(EXEC) ]; then ./$(EXEC); else echo "Error $(EXEC) not found"; exit 1; fi
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
	rm -rf $(OBJDIR) $(DEPSDIR)

fclean: clean
	rm -rf $(EXEC)

re: fclean all

-include $(DEPS)