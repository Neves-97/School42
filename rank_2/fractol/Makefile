NAME	:=	fractol

CC		:=	gcc
CFLAGS	:= 	-Wall -Wextra -Werror -O3 -g -I$(PATH_INCLUDES) -Imlx_linux -D_REENTRANT

PATH_SRC		:=	./
PATH_INCLUDES	:=	./incs
PATH_BUILD		:= ./build
PATH_OBJS		:= $(PATH_BUILD)/objs

SRCS			:=	$(PATH_SRC)/main.c \
					$(PATH_SRC)/events.c \
					$(PATH_SRC)/arg_parser.c \
					$(PATH_SRC)/fractol_utils.c \
					$(PATH_SRC)/mandelbrot.c\
					$(PATH_SRC)/julia.c\
					$(PATH_SRC)/burning_ship.c\
					$(PATH_SRC)/draw.c\
					



OBJ				:= $(subst .c,.o,$(subst $(PATH_SRC), $(PATH_OBJS), $(SRCS)))

all:$(NAME)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) -o $(@) $^ -I$(PATH_INCLUDES)  $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
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
