#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/12/21 17:06:45 by mdauphin          #+#    #+#             *#
#*   Updated: 2017/02/10 21:39:50 by mdauphin         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = fillit

SRC_PATH = ./srcs/

SRC_NAME = 	main.c\
			arrange.c \
			checker.c \
			map.c \
			read.c \
			solve.c \
			forme.c

OBJ_PATH = ./obj/

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = ./includes/

LIB = ./libft/libft.a

CC = gcc
CFLAGS = -Werror -Wall -Wextra

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(LIB) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) i2> /dev/null || echo "" > /dev/null

fclean: clean
	rm -fv $(NAME) 

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)fillit.h

.PHONY: all clean fclean re norme
