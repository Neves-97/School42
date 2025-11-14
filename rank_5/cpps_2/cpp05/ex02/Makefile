NAME    = ex02
CC      = c++ -Wall -Werror -Wextra -std=c++98
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = incs

SRC  	= $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/Bureaucrat.cpp \
		  $(SRC_DIR)/AForm.cpp \
		  $(SRC_DIR)/PresidentialPardonForm.cpp \
		  $(SRC_DIR)/RobotomyRequestForm.cpp \
		  $(SRC_DIR)/ShrubberyCreationForm.cpp \

OBJ     = $(OBJ_DIR)/main.o \
          $(OBJ_DIR)/Bureaucrat.o\
		  $(OBJ_DIR)/AForm.o\
		  $(OBJ_DIR)/PresidentialPardonForm.o \
		  $(OBJ_DIR)/RobotomyRequestForm.o \
		  $(OBJ_DIR)/ShrubberyCreationForm.o \

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/Bureaucrat.o: $(SRC_DIR)/Bureaucrat.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/AForm.o: $(SRC_DIR)/AForm.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/PresidentialPardonForm.o: $(SRC_DIR)/PresidentialPardonForm.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/RobotomyRequestForm.o: $(SRC_DIR)/RobotomyRequestForm.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/ShrubberyCreationForm.o: $(SRC_DIR)/ShrubberyCreationForm.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re