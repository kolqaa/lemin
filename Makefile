#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 22:30:25 by nsimonov          #+#    #+#              #
#    Updated: 2017/03/29 22:51:37 by nsimonov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

GCC = gcc -Wall -Wextra -Werror

SRC =	main.c \
		algorithm.c \
		check_ant.c \
		create_matrix.c \
		func_for_lst.c \
		get_rooms_and_links.c \
		go_ant.c \
		help_func.c \
		help_room_links.c \
		take_sizes_and_clear_free.c \
		take_start_end_room.c \
		validation.c \
		make_and_reset.c \
		my_strjoins.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		gcc -Wall -Wextra -Werror -c $(SRC)
		cd libft/ && $(MAKE)
		cd libft/ft_printf/ && $(MAKE)
		gcc -o $(NAME) $(OBJ) libft/ft_printf/libftprintf.a libft/libft.a

%.o : %.c
	$(GCC) -c -o  $@ $<

clean:
		rm -f $(OBJ)
		make clean -C libft/
		make clean -C libft/ft_printf/

fclean: clean
		make fclean -C libft/
		make fclean -C libft/ft_printf/
		rm -f $(NAME)

re: fclean all
