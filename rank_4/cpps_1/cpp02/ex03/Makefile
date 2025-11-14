NAME    = bsp
CC      = c++ -Wall -Werror -Wextra -std=c++98
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = incs

SRC  	= $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/Fixed.cpp \
		  $(SRC_DIR)/bsp.cpp \
		  $(SRC_DIR)/Point.cpp \

OBJ     = $(OBJ_DIR)/main.o \
          $(OBJ_DIR)/Fixed.o\
		  $(OBJ_DIR)/bsp.o \
		  $(OBJ_DIR)/Point.o \

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/Fixed.o: $(SRC_DIR)/Fixed.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/bsp.o: $(SRC_DIR)/bsp.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/Point.o: $(SRC_DIR)/Point.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re