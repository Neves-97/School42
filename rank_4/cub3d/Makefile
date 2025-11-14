# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 11:04:46 by hcorrea-          #+#    #+#              #
#    Updated: 2024/01/28 11:04:46 by hcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		=	\033[0;32m
RED			=	\033[0;31m
YELLOW	=	\033[0;33m
END			=	\033[0m

NAME		=	cub3D

SRC_DIR = src
OBJ_DIR =	obj
INC_DIR = inc

SRC     =	src/check_horizontal.c src/check_map.c src/check_vertical.c src/colors.c src/direction.c src/draw_utils.c src/draw.c src/exit.c src/hook.c src/image.c\
					src/inits.c src/main.c src/parser_utils.c src/parser_utils2.c src/parser.c src/utils.c	
OBJ     =	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

CC			=	cc
CFLAGS	=	-Wall -Wextra -Werror -I./inc
LDFLAGS	=	-L./mlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz

RM					=	rm -rf
MKDIR				=	mkdir -p
MAKE				=	make -C
ERRIGNORE		=	2>/dev/null

LIBFT_DIR			=	libft
LIBFT_HEADER	=	$(LIBFT_DIR)/inc/libft.h
LIBFT_LIB			=	libft.a
LIBFT_FILE		:=	$(LIBFT_DIR)/$(LIBFT_LIB)

all:			$(NAME)
					
$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $(OBJ_DIR)
								@$(MKDIR) $(dir $@)
								@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(LIBFT_FILE) $(OBJ)
					@echo "$(YELLOW)Compiling Minilibx...$(END)"
					@$(MAKE) mlx > /dev/null 2>&1
					@echo "$(GREEN)Minilibx successfully compiled!$(END)"
					@sleep 0.5
					@clear
					@echo "$(YELLOW)Compiling Cub3D...$(END)"
					@$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LIBFT_FILE) -o $@
					@echo "$(GREEN)Cub3D successfully compiled!$(END)"
					@sleep 0.5
					@clear
					@echo "$(YELLOW)Checking Norminette...$(END)"
					@norminette $(SRC_DIR) $(LIBFT_DIR) $(INC_DIR) > norminette_output.txt; \
					RESULT=$$?; \
					if [ $$RESULT -eq 0 ]; then \
						echo "$(GREEN)Norminette check passed!$(END)"; \
						sleep 0.5; \
						clear; \
					else \
						grep -E "Error|Warning:" norminette_output.txt; \
						echo "$(RED)Norminette check failed!$(END)"; \
					fi; \
					rm -f norminette_output.txt

$(OBJ_DIR):
					@$(MKDIR) $(OBJ_DIR)

%.o:				%.c
					@$(CC) $(CFLAGS) -I $(HEADER) -I $(LIBFT_HEADER) -Imlx -c $< -o $@		

libft:		$(LIBFT_FILE)

$(LIBFT_FILE):
					@$(MAKE) $(LIBFT_DIR)
					@sleep 0.5
					@clear

clean:
					@$(RM) $(OBJ_DIR)
					@rm -rf mlx/obj mlx/test/main.o mlx/test/mlx-test > /dev/null 2>&1
					@$(MAKE) $(LIBFT_DIR) clean
					@clear
					@echo "$(RED)All objects deleted!$(END)"

fclean:		clean
					@$(RM) $(NAME)
					@$(MAKE) $(LIBFT_DIR) fclean
					@echo "$(RED)All executables deleted!$(END)"
					@sleep 0.5
					@clear

re:				fclean all

v:				all
					$(eval ORIGINAL_CFLAGS := $(CFLAGS))
					$(eval override CFLAGS := $(filter-out -g -fsanitize=address,$(CFLAGS)))
					valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./cub3D
					$(eval override CFLAGS := $(ORIGINAL_CFLAGS))

.PHONY:		all clean fclean re