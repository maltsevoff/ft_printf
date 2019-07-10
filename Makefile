# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 13:36:57 by omaltsev          #+#    #+#              #
#    Updated: 2019/02/08 13:59:53 by omaltsev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = extra.c ft_atoi.c ft_digit.c ft_itoa.c ft_memset.c\
	ft_printf.c ft_putchar.c ft_putstr.c ft_strchr.c ft_strdup.c\
	ft_strjoin.c ft_strlen.c ft_strnew.c lists.c options.c ft_char.c\
	ft_string.c ft_octal.c ft_strcmp.c ft_float.c ft_point.c extra2.c\
	ft_digit_2.c ft_octal_2.c ft_printf_2.c

OBJ = extra.o ft_atoi.o ft_digit.o ft_itoa.o ft_memset.o\
	ft_printf.o ft_putchar.o ft_putstr.o ft_strchr.o ft_strdup.o\
	ft_strjoin.o ft_strlen.o ft_strnew.o lists.o options.o ft_char.o\
	ft_string.o ft_octal.o ft_strcmp.o ft_float.o ft_point.o extra2.o\
	ft_digit_2.o ft_octal_2.o ft_printf_2.o

INC = Includes

all: $(NAME)

$(NAME):
	@gcc -c $(SRC) -I $(INC)
	@ar -r $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
