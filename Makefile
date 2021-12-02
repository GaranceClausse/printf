# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gclausse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:46:56 by gclausse          #+#    #+#              #
#    Updated: 2021/12/02 15:26:34 by gclausse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= ft_putnbr_base.c\
	 ft_printf.c

PARENT_DIR= libft

LIBFT_PATH= $(PARENT_DIR)

NAME= libftprintf.a

CC= gcc

CFLAGS= -Wall -Werror -Wextra -I${LIBFT_PATH}

OBJ= ${SRC:.c=.o}

OBJBONUS= ${SRCBONUS:.c=.o}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	make -C $(LIBFT_PATH)
	ar -rc ${NAME} ${OBJ} -L ${LIBFT_PATH} -libft

clean:
	make clean -C $(LIBFT_PATH) && rm -f *.o

fclean: clean
	make clean -C $(LIBFT_PATH) && rm -f ${NAME}

re: fclean all

.PHONY: clean fclean all re
