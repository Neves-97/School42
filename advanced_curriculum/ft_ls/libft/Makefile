# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 18:52:47 by roda-min          #+#    #+#              #
#    Updated: 2022/11/24 18:52:49 by roda-min         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a

CC		:=	gcc
CFLAGS	:= 	-Wall -Werror -Wextra -I./incs

PATH_SRC		:=	./
PATH_INCLUDES	:=	./incs
PATH_BUILD		:= ./build
PATH_OBJS		:= $(PATH_BUILD)/objs

SRCS			:=	$(PATH_SRC)/ft_atoi.c \
					$(PATH_SRC)/ft_bzero.c \
					$(PATH_SRC)/ft_calloc.c \
					$(PATH_SRC)/ft_isalnum.c \
					$(PATH_SRC)/ft_isalpha.c\
					$(PATH_SRC)/ft_isascii.c \
					$(PATH_SRC)/ft_isdigit.c \
					$(PATH_SRC)/ft_isprint.c \
					$(PATH_SRC)/ft_itoa.c \
					$(PATH_SRC)/ft_memchr.c\
					$(PATH_SRC)/ft_memcmp.c\
					$(PATH_SRC)/ft_memcpy.c \
					$(PATH_SRC)/ft_memmove.c\
					$(PATH_SRC)/ft_memset.c\
					$(PATH_SRC)/ft_putchar_fd.c\
					$(PATH_SRC)/ft_putendl_fd.c\
					$(PATH_SRC)/ft_putnbr_fd.c\
					$(PATH_SRC)/ft_putstr_fd.c\
					$(PATH_SRC)/ft_split.c\
					$(PATH_SRC)/ft_strchr.c\
					$(PATH_SRC)/ft_strdup.c\
					$(PATH_SRC)/ft_striteri.c\
					$(PATH_SRC)/ft_strjoin.c\
					$(PATH_SRC)/ft_strlcat.c\
					$(PATH_SRC)/ft_strlcpy.c\
					$(PATH_SRC)/ft_strlen.c\
					$(PATH_SRC)/ft_strmapi.c\
					$(PATH_SRC)/ft_strncmp.c\
					$(PATH_SRC)/ft_strnstr.c\
					$(PATH_SRC)/ft_strrchr.c\
					$(PATH_SRC)/ft_strtrim.c\
					$(PATH_SRC)/ft_substr.c\
					$(PATH_SRC)/ft_tolower.c\
					$(PATH_SRC)/ft_toupper.c\
					$(PATH_SRC)/ft_lstadd_back.c\
					$(PATH_SRC)/ft_lstadd_front.c\
					$(PATH_SRC)/ft_lstclear.c\
					$(PATH_SRC)/ft_lstdelone.c\
					$(PATH_SRC)/ft_lstiter.c\
					$(PATH_SRC)/ft_lstlast.c\
					$(PATH_SRC)/ft_lstmap.c\
					$(PATH_SRC)/ft_lstnew.c\
					$(PATH_SRC)/ft_lstsize.c\

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

.PHONY:	all clean fclean re bonus