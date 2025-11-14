NAME    = ircserv
CC      = c++ -g -Wall -Werror -Wextra -std=c++98
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = incs

SRC  	= $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/validation.cpp \
		  $(SRC_DIR)/server.cpp \
		  $(SRC_DIR)/client.cpp \
		  $(SRC_DIR)/channel.cpp \
		  $(SRC_DIR)/commands/nickname.cpp \
		  $(SRC_DIR)/commands/join.cpp \
		  $(SRC_DIR)/commands/user.cpp \
		  $(SRC_DIR)/commands/pass.cpp \
		  $(SRC_DIR)/commands/privmsg.cpp \
		  $(SRC_DIR)/commands/kick.cpp \
		  $(SRC_DIR)/commands/invite.cpp \
		  $(SRC_DIR)/commands/topic.cpp \
		  $(SRC_DIR)/commands/mode.cpp \
		  $(SRC_DIR)/commands/mode_utils.cpp \
		  $(SRC_DIR)/commands/who.cpp \
		  $(SRC_DIR)/commands/part.cpp \

OBJ     = $(OBJ_DIR)/main.o \
          $(OBJ_DIR)/validation.o\
		  $(OBJ_DIR)/server.o \
		  $(OBJ_DIR)/client.o \
		  $(OBJ_DIR)/channel.o \
		  $(OBJ_DIR)/commands/nickname.o \
		  $(OBJ_DIR)/commands/join.o \
		  $(OBJ_DIR)/commands/user.o \
		  $(OBJ_DIR)/commands/pass.o \
		  $(OBJ_DIR)/commands/privmsg.o \
		  $(OBJ_DIR)/commands/kick.o \
		  $(OBJ_DIR)/commands/invite.o \
		  $(OBJ_DIR)/commands/topic.o \
		  $(OBJ_DIR)/commands/mode.o \
		  $(OBJ_DIR)/commands/mode_utils.o \
		  $(OBJ_DIR)/commands/who.o \
		  $(OBJ_DIR)/commands/part.o \

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/commands

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/validation.o: $(SRC_DIR)/validation.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/server.o: $(SRC_DIR)/server.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/client.o: $(SRC_DIR)/client.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/commands/nickname.o: $(SRC_DIR)/commands/nickname.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/commands/join.o: $(SRC_DIR)/commands/join.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/channel.o: $(SRC_DIR)/channel.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/commands/user.o: $(SRC_DIR)/commands/user.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/commands/pass.o: $(SRC_DIR)/commands/pass.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/commands/privmsg.o: $(SRC_DIR)/commands/privmsg.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/commands/kick.o: $(SRC_DIR)/commands/kick.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/commands/invite.o: $(SRC_DIR)/commands/invite.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/commands/topic.o: $(SRC_DIR)/commands/topic.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/commands/mode.o: $(SRC_DIR)/commands/mode.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/commands/mode_utils.o: $(SRC_DIR)/commands/mode_utils.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/commands/who.o: $(SRC_DIR)/commands/who.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR)/commands/part.o: $(SRC_DIR)/commands/part.cpp
	@$(CC) -c $< -o $@ -I $(INC_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re