NAME    = Weapon
CC      = c++ -Wall -Werror -Wextra -std=c++98
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = incs

SRC  	= $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/HumanA.cpp \
		  $(SRC_DIR)/HumanB.cpp \
		  $(SRC_DIR)/Weapon.cpp

OBJ     = $(OBJ_DIR)/main.o \
          $(OBJ_DIR)/HumanA.o\
		  $(OBJ_DIR)/HumanB.o \
		  $(OBJ_DIR)/Weapon.o

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/HumanA.o: $(SRC_DIR)/HumanA.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/HumanB.o: $(SRC_DIR)/HumanB.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/Weapon.o: $(SRC_DIR)/Weapon.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re