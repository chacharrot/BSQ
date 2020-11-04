# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scha <scha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 06:00:09 by scha              #+#    #+#              #
#    Updated: 2020/11/05 07:16:57 by scha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: 
	gcc -Wall -Werror -Wextra ./srcs/check.c ./srcs/check2.c ./srcs/ft_putchar.c ./srcs/map_plus.c ./srcs/print_map.c ./srcs/ft_is_numeric.c ./srcs/ft_is_printable.c ./srcs/memory.c ./srcs/std_read.c  ./srcs/ft_n_atio.c ./srcs/main.c -I ./includes/ -o bsq

clean:
	rm -f ./srcs/*.o

fclean: clean
	rm -f bsq

re: fclean all
