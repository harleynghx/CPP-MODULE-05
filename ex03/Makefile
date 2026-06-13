NAME = ex02
SRC_DIR = ./srcs
OBJ_DIR = obj
SRCS = $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/Bureaucrat.cpp \
       $(SRC_DIR)/AForm.cpp \
       $(SRC_DIR)/ShrubberyCreationForm.cpp \
       $(SRC_DIR)/RobotomyRequestForm.cpp \
       $(SRC_DIR)/PresidentialPardonForm.cpp
	   $(SRC_DIR)/Intern.cpp

OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re
