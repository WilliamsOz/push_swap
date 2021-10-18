# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 19:15:44 by user42            #+#    #+#              #
#    Updated: 2021/10/18 18:11:43 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror
PATHCOMMANDS = ./srcs/lk_commands/
PATHUTILSF = ./srcs/utils_functions/
PATHPREPFCT = ./srcs/prepare_stacks_functions/
PATHCOMONFCT = ./srcs/common_functions/
PATHSALGO = ./srcs/simple_algorithms/
PATHCALGO = ./srcs/complex_algorithms/
PATHALGOCMP = ./srcs/algorithms_move_compare/
FILESC = push_swap.c $(PATHUTILSF)check_errors.c $(PATHUTILSF)get_position.c \
$(PATHCOMMANDS)push_commands.c $(PATHCOMMANDS)reverse_rotate_commands.c \
$(PATHCOMMANDS)rotate_commands.c $(PATHCOMMANDS)swap_commands.c \
$(PATHUTILSF)utils.c $(PATHSALGO)three_four_five.c \
$(PATHSALGO)rotate_algorithm.c $(PATHSALGO)r_rotate_algorithm.c \
$(PATHSALGO)swap_algorithm.c $(PATHCALGO)rarb_algorithm.c \
$(PATHCALGO)rrarb_algorithm.c $(PATHCALGO)rrarrb_algorithm.c \
$(PATHALGOCMP)rarb_comp.c $(PATHALGOCMP)rrarb_comp.c \
$(PATHALGOCMP)rrarrb_comp.c $(PATHCALGO)rarrb_algorithm.c \
$(PATHALGOCMP)rarrb_comp.c $(PATHPREPFCT)prepare_low_stack.c \
$(PATHPREPFCT)prepare_big_stack.c $(PATHCOMONFCT)motor.c \
$(PATHSALGO)rr_algorithm.c $(PATHSALGO)rrr_algorithm.c

FILESO = push_swap.o $(PATHUTILSF)check_errors.o $(PATHUTILSF)get_position.o \
$(PATHCOMMANDS)push_commands.o $(PATHCOMMANDS)reverse_rotate_commands.o \
$(PATHCOMMANDS)rotate_commands.o $(PATHCOMMANDS)swap_commands.o \
$(PATHUTILSF)utils.o $(PATHSALGO)three_four_five.o \
$(PATHSALGO)rotate_algorithm.o $(PATHSALGO)r_rotate_algorithm.o \
$(PATHSALGO)swap_algorithm.o $(PATHCALGO)rarb_algorithm.o \
$(PATHCALGO)rrarb_algorithm.o $(PATHCALGO)rrarrb_algorithm.o \
$(PATHALGOCMP)rarb_comp.o $(PATHALGOCMP)rrarb_comp.o \
$(PATHALGOCMP)rrarrb_comp.o $(PATHCALGO)rarrb_algorithm.o \
$(PATHALGOCMP)rarrb_comp.o $(PATHPREPFCT)prepare_low_stack.o \
$(PATHPREPFCT)prepare_big_stack.o $(PATHCOMONFCT)motor.o \
$(PATHSALGO)rr_algorithm.o $(PATHSALGO)rrr_algorithm.o

all : $(NAME)

$(NAME)	:
	cd libft && make all && make clean && mv libft.a ..
	gcc $(FLAGS) $(FILESC) libft.a -o $(NAME)

clean	:
	rm -Rf $(FILESO) libft.a

fclean : clean
	rm -Rf $(NAME)

re : fclean all