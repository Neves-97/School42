NAME    = ex01
CC      = c++ -Wall -Werror -Wextra -std=c++98
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = incs

SRC  	= $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/Animal.cpp \
		  $(SRC_DIR)/Brain.cpp \
		  $(SRC_DIR)/Cat.cpp \
		  $(SRC_DIR)/Dog.cpp \
		  $(SRC_DIR)/WrongAnimal.cpp \
		  $(SRC_DIR)/WrongCat.cpp \

OBJ     = $(OBJ_DIR)/main.o \
          $(OBJ_DIR)/Animal.o\
		  $(OBJ_DIR)/Brain.o\
		  $(OBJ_DIR)/Cat.o\
		  $(OBJ_DIR)/Dog.o\
		  $(OBJ_DIR)/WrongAnimal.o \
		  $(OBJ_DIR)/WrongCat.o \

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/Animal.o: $(SRC_DIR)/Animal.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/Brain.o: $(SRC_DIR)/Brain.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/Cat.o: $(SRC_DIR)/Cat.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/Dog.o: $(SRC_DIR)/Dog.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/WrongAnimal.o: $(SRC_DIR)/WrongAnimal.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/WrongCat.o: $(SRC_DIR)/WrongCat.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
