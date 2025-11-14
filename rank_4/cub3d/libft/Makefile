# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 17:36:38 by hcorrea-          #+#    #+#              #
#    Updated: 2024/03/11 14:01:41 by hcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	=	\033[0;32m
RED		=	\033[0;31m
YELLOW	=	\033[0;33m
END		=	\033[0m

CFLAGS	=	-Wall -Wextra -Werror -I$(INC_DIR) -fPIE

NAME 	= 	libft.a

SRC 	= 	src/ft_memset.c src/ft_bzero.c src/ft_memcpy.c src/ft_memmove.c src/ft_memchr.c\
			src/ft_memcmp.c src/ft_strlen.c src/ft_strlcpy.c src/ft_strlcat.c src/ft_strchr.c src/ft_strrchr.c\
			src/ft_substr.c src/ft_putchar_fd.c src/ft_putstr_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c\
			src/ft_strnstr.c src/ft_strncmp.c src/ft_atoi.c src/ft_isalpha.c src/ft_isdigit.c src/ft_isalnum.c\
			src/ft_isascii.c src/ft_isprint.c src/ft_toupper.c src/ft_tolower.c src/ft_calloc.c src/ft_strdup.c\
			src/ft_strjoin.c src/ft_strtrim.c src/ft_strmapi.c src/ft_striteri.c src/ft_itoa.c src/ft_split.c\
			src/ft_strcmp.c src/get_next_line.c src/ft_atod.c src/ft_iswhite.c src/ft_strncpy.c

BONUS 	= 	bonus/ft_lstnew.c bonus/ft_lstadd_front.c bonus/ft_lstsize.c bonus/ft_lstlast.c bonus/ft_lstadd_back.c\
			bonus/ft_lstdelone.c bonus/ft_lstclear.c bonus/ft_lstiter.c bonus/ft_lstmap.c\

RM 		=	rm -rf

OBJ		=	$(SRC:src/%.c=$(OBJ_DIR)/%.o)
OBJ_B	=	$(BONUS:bonus/%.c=$(OBJ_DIR)/%.o)
INC_DIR	=	inc
OBJ_DIR	=	obj

OBJF	=	.cache_exists

all:			$(NAME) bonus

$(NAME): 		$(OBJ)
				@echo "$(YELLOW)Compiling Libft...$(END)"
				@ar rcs $(NAME) $(OBJ)
				@echo "$(GREEN)Libft succesfully compiled!$(END)"

$(OBJ_DIR)/%.o:	src/%.c | $(OBJF)
				@$(CC) $(CFLAGS) -c $(^) -o $(@)

$(OBJ_DIR)/%.o:	bonus/%.c | $(OBJF)
				@$(CC) $(CFLAGS) -c $(^) -o $(@)

$(OBJF):
				@mkdir -p $(OBJ_DIR)
						
clean: 		
				@rm -rf $(OBJ_DIR)
				@echo "$(RED)Libft objects deleted!$(END)"

fclean: 		clean
				@rm -rf $(NAME)
				@echo "$(RED)Libft lib deleted!$(END)"

re:				fclean	all

bonus:			$(NAME) $(OBJ_B)
				@echo "$(YELLOW)Compiling Libft bonus...$(END)"
				@ar rcs $(NAME) $(OBJ_B)
				@echo "$(GREEN)Libft bonus succesfully compiled!$(END)"

.PHONY:			all clean fclean re bonus
