NAME    = Zombie
CC      = c++ -Wall -Werror -Wextra -std=c++98
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = incs

SRC  	= $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/ZombieHorde.cpp \
		  $(SRC_DIR)/Zombie.cpp 

OBJ     = $(OBJ_DIR)/main.o \
          $(OBJ_DIR)/ZombieHorde.o\
		  $(OBJ_DIR)/Zombie.o

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/ZombieHorde.o: $(SRC_DIR)/ZombieHorde.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/Zombie.o: $(SRC_DIR)/Zombie.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re