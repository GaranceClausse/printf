# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gclausse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:46:56 by gclausse          #+#    #+#              #
#    Updated: 2021/12/02 14:29:31 by gclausse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= ft_putnbr_base.c\
	 ft_printf.c

PARENT_DIR		= $(shell dirname $(shell pwd))

LIBFT_PATH= $(PARENT_DIR)

NAME= libftprintf.a

CC= gcc

CFLAGS= -Wall -Werror -Wextra

OBJ= ${SRC:.c=.o}

OBJBONUS= ${SRCBONUS:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	ar -rc ${NAME} ${OBJ} -L$(LIBFT_PATH) -lft

clean:
	rmake clean -C $(LIBFT_PATH) && m -f *.o

fclean: clean
	make clean -C $(LIBFT_PATH) && rm -f ${NAME}

re: fclean all

.PHONY: clean fclean all re
