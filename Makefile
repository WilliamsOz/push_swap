# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 19:15:44 by user42            #+#    #+#              #
#    Updated: 2021/10/17 11:57:05 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror
PATHCOMMANDS = ./srcs/lk_commands/
PATHSRC = ./srcs/
PATHSALGO = ./srcs/sort_algorithm/simple_algorithms/
PATHCALGO = ./srcs/sort_algorithm/complex_algorithms/
FILESC = push_swap.c $(PATHSRC)check_errors.c $(PATHSRC)get_position.c \
$(PATHCOMMANDS)push_commands.c $(PATHCOMMANDS)reverse_rotate_commands.c \
$(PATHCOMMANDS)rotate_commands.c $(PATHCOMMANDS)swap_commands.c \
$(PATHSRC)utils.c $(PATHSALGO)three_four_five.c \
$(PATHSALGO)rotate_algorithm.c $(PATHSALGO)r_rotate_algorithm.c \
$(PATHSALGO)swap_algorithm.c $(PATHCALGO)d_rotate_algorithm.c \
$(PATHCALGO)rrarb_algorithm.c

FILESO = push_swap.o $(PATHSRC)check_errors.o $(PATHSRC)get_position.o \
$(PATHCOMMANDS)push_commands.o $(PATHCOMMANDS)reverse_rotate_commands.o \
$(PATHCOMMANDS)rotate_commands.o $(PATHCOMMANDS)swap_commands.o \
$(PATHSRC)utils.o $(PATHSALGO)three_four_five.o \
$(PATHSALGO)rotate_algorithm.o $(PATHSALGO)r_rotate_algorithm.o \
$(PATHSALGO)swap_algorithm.o $(PATHCALGO)d_rotate_algorithm.o \
$(PATHCALGO)rrarb_algorithm.o

all : $(NAME)

$(NAME)	:
	cd libft && make all && make clean && mv libft.a ..
	gcc $(FLAGS) $(FILESC) libft.a -o $(NAME)

clean	:
	rm -Rf $(FILESO) libft.a

fclean : clean
	rm -Rf $(NAME)

re : fclean all