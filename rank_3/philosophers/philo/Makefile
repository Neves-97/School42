# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: neves <neves@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 15:38:06 by neves             #+#    #+#              #
#    Updated: 2023/10/19 16:02:40 by neves            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := philo
CC      := cc
FLAGS   := -Wall -Wextra -Werror -g -pthread -fsanitize=address

SRCS    := srcs/utils.c \
           srcs/init.c \
           srcs/check.c \
           srcs/threads.c \
           srcs/death.c \
           srcs/free.c \
           srcs/actions.c \
           srcs/routine.c \
           srcs/main.c \
           srcs/time.c \
           srcs/forks.c

OBJS    := $(SRCS:.c=.o)

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

RM      := rm -f

${NAME}: ${OBJS}
	${CC} ${FLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

bonus: all

clean:
	@ ${RM} ${OBJS}

fclean: clean
	@ ${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re



