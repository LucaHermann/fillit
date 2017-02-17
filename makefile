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

NAME	= fillit

SRC		=	main.c arrange.c checker.c map.c read.c solve.c forme.c

OBJ		= $(addprefix srcs/,$(SRC:.c=.o))

CFLAGS	=  -Werror -Wextra -Wall -Iincludes/ -Ilibft/includes/

$(NAME): $(OBJ)
	@make -C libft
	 @gcc $(OBJ) -o $(NAME) -L libft/ -lft -Ilibft/includes/

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@make -C libft/ fclean

re: fclean $(NAME)
