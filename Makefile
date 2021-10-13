# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 19:15:44 by user42            #+#    #+#              #
#    Updated: 2021/10/13 10:21:51 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror
PATHCOMMANDS = ./srcs/lk_commands/
PATHSRC = ./srcs/
PATHALGO = ./srcs/sort_algorithm/
FILESC = push_swap.c $(PATHSRC)check_errors.c $(PATHSRC)get_position.c \
$(PATHCOMMANDS)push_commands.c $(PATHCOMMANDS)reverse_rotate_commands.c \
$(PATHCOMMANDS)rotate_commands.c $(PATHCOMMANDS)swap_commands.c \
$(PATHALGO)three_four_five.c $(PATHALGO)rotate_algorithm.c \
$(PATHALGO)r_rotate_algorithm.c $(PATHSRC)utils.c $(PATHALGO)swap_algorithm.c \
$(PATHALGO)d_rotate_algorithm.c

FILESO = push_swap.o $(PATHSRC)check_errors.o $(PATHSRC)get_position.o \
$(PATHCOMMANDS)push_commands.o $(PATHCOMMANDS)reverse_rotate_commands.o \
$(PATHCOMMANDS)rotate_commands.o $(PATHCOMMANDS)swap_commands.o \
$(PATHALGO)three_four_five.o $(PATHALGO)rotate_algorithm.o \
$(PATHALGO)r_rotate_algorithm.o $(PATHSRC)utils.o $(PATHALGO)swap_algorithm.o \
$(PATHALGO)d_rotate_algorithm.o

all : $(NAME)

$(NAME)	:
	cd libft && make all && make clean && mv libft.a ..
	gcc $(FLAGS) $(FILESC) libft.a -o $(NAME)

clean	:
	rm -Rf $(FILESO) libft.a

fclean : clean
	rm -Rf $(NAME)

re : fclean all