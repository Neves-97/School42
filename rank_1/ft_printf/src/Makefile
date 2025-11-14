# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 11:39:26 by roda-min          #+#    #+#              #
#    Updated: 2023/03/31 13:41:53 by roda-min         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I./incs

PATH_SRC		:=	./
PATH_INCLUDES	:=	./incs
PATH_BUILD		:= ./build
PATH_OBJS		:= $(PATH_BUILD)/objs

SRCS := $(PATH_SRC)/ft_printf.c \
 					$(PATH_SRC)/ft_flags.c \
					$(PATH_SRC)/ft_printf_c.c \
					$(PATH_SRC)/ft_printf_s.c \
					$(PATH_SRC)/ft_printf_di.c \
					$(PATH_SRC)/ft_printf_p.c \
					$(PATH_SRC)/ft_printf_u.c \
					$(PATH_SRC)/ft_printf_x.c \
					$(PATH_SRC)/ft_printf_xx.c \
					$(PATH_SRC)/ft_printf_utils.c \

OBJ				:= $(subst .c,.o,$(subst $(PATH_SRC), $(PATH_OBJS), $(SRCS)))

all:$(NAME)

$(NAME): $(OBJ)
		@$(AR) rcs $(NAME) $(OBJ)
		@printf "\033[44m[$(NAME) BUILT!]\033[0m\n"

$(PATH_OBJS)/%.o: $(PATH_SRC)/%.c | $(PATH_BUILD)
		@$(CC) $(CFLAGS)  -c $(^) -o $@
		@printf "\033[36m[Building ${@F}]\033[0m\n"


$(PATH_BUILD):
		@mkdir -p $(PATH_BUILD)
		@mkdir -p $(PATH_OBJS) 

clean:
		@printf "\033[38;5;1m[Cleaning objects!]\033[0m\n"
		@rm -rf $(PATH_OBJS)

fclean: clean
		@printf "\033[38;5;1m[Cleaning Bin!]\033[0m\n"
		@rm -rf $(PATH_BUILD) $(NAME)

re: fclean all

.PHONY:	all clean fclean re 