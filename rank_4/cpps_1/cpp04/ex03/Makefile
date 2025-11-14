NAME    = ex03
CC      = c++ -Wall -Werror -Wextra -std=c++98
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = incs

SRC  	= $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/AMateria.cpp \
		  $(SRC_DIR)/Character.cpp \
		  $(SRC_DIR)/Cure.cpp \
		  $(SRC_DIR)/Ice.cpp \
		  $(SRC_DIR)/MateriaSource.cpp \

OBJ     = $(OBJ_DIR)/main.o \
          $(OBJ_DIR)/AMateria.o\
		  $(OBJ_DIR)/Character.o\
		  $(OBJ_DIR)/Cure.o\
		  $(OBJ_DIR)/Ice.o\
		  $(OBJ_DIR)/MateriaSource.o \

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/AMateria.o: $(SRC_DIR)/AMateria.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/Character.o: $(SRC_DIR)/Character.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/Cure.o: $(SRC_DIR)/Cure.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/Ice.o: $(SRC_DIR)/Ice.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/MateriaSource.o: $(SRC_DIR)/MateriaSource.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
