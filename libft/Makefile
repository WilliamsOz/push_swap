# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 14:45:54 by user42            #+#    #+#              #
#    Updated: 2021/10/25 21:02:57 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
FILESC = ft_atoi.c ft_list_size.c lk_ascending_order_check.c ft_isdigit.c \
ft_strcmp.c free_lk.c get_next_line.c free_lk.c ft_strlen.c
FILESO = ft_atoi.o ft_list_size.o lk_ascending_order_check.o ft_isdigit.o \
ft_strcmp.o free_lk.o get_next_line.o free_lk.o ft_strlen.o

all : $(NAME)

$(NAME) :
	gcc $(FLAGS) -c $(FILESC)
	ar -rcs $(NAME) $(FILESO)

clean :
	rm -rf $(FILESO) $(BONUSO)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus :	fclean
	gcc $(FLAGS) -c $(FILESC) $(BONUSC)
	ar -rcs $(NAME) $(FILESO) $(BONUSO)