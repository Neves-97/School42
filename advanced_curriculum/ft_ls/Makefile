# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                                              #
# **************************************************************************** #

NAME    := ft_ls
CC      := gcc
CFLAGS  := -Wall -Wextra -Werror
INCS    := -I libft/incs
LIBS    := libft/libft.a

SRC     := srcs/main.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(INCS) $(SRC) $(LIBS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re
