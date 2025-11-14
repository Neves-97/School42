NAME    = ex02
CC      = c++ -Wall -Werror -Wextra -std=c++98
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = incs

SRC  	= $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/A.cpp \
	      $(SRC_DIR)/B.cpp \
		  $(SRC_DIR)/Base.cpp \
		  $(SRC_DIR)/C.cpp \	

OBJ     = $(OBJ_DIR)/main.o \
          $(OBJ_DIR)/A.o\
		  $(OBJ_DIR)/B.o\
		  $(OBJ_DIR)/Base.o\
		  $(OBJ_DIR)/C.o\

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/A.o: $(SRC_DIR)/A.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/B.o: $(SRC_DIR)/B.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/Base.o: $(SRC_DIR)/Base.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/C.o: $(SRC_DIR)/C.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re