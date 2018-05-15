# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukim <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 20:31:13 by jukim             #+#    #+#              #
#    Updated: 2018/05/15 16:51:03 by jukim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf 
FILES = ft_printf.c
SRC = $(addprefix src/, $(FILES))
CFLAGS = -I ./includes/ -I src/libft -Wall -Wextra -Werror
LFLAGS = -L ./src/libft/ -lft
OBJ = $(FILES:.c=.o)

all = $(NAME)

$(NAME):
	@make -C src/libft
	@gcc $(CFLAGS) -c $(SRC)
	@gcc $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f *.o *~ */*.o */*~

fclean: clean
	@make fclean -C ./src/libft
	@/bin/rm -f $(NAME)

re: fclean all
