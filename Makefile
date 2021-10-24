# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/14 19:15:44 by user42            #+#    #+#              #
#    Updated: 2021/10/24 14:49:01 by wiozsert         ###   ########.fr        #
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
PATHOBJ = ./obj/
LIBFTFILESO = ft_atoi.o ft_isdigit.o ft_list_size.o lk_ascending_order_check.o
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
$(PATHPREPFCT)prepare_big_stack.c $(PATHCOMONFCT)motor.c 

FILESO = push_swap.o check_errors.o get_position.o push_commands.o \
reverse_rotate_commands.o rotate_commands.o swap_commands.o \
utils.o three_four_five.o rotate_algorithm.o r_rotate_algorithm.o \
swap_algorithm.o rarb_algorithm.o rrarb_algorithm.o rrarrb_algorithm.o \
rarb_comp.o rrarb_comp.o rrarrb_comp.o rarrb_algorithm.o rarrb_comp.o \
prepare_low_stack.o prepare_big_stack.o motor.o 

ALLOBJ = $(PATHOBJ)ft_atoi.o $(PATHOBJ)ft_isdigit.o $(PATHOBJ)ft_list_size.o \
$(PATHOBJ)lk_ascending_order_check.o $(PATHOBJ)push_swap.o \
$(PATHOBJ)check_errors.o $(PATHOBJ)get_position.o $(PATHOBJ)push_commands.o \
$(PATHOBJ)reverse_rotate_commands.o $(PATHOBJ)rotate_commands.o \
$(PATHOBJ)swap_commands.o $(PATHOBJ)utils.o $(PATHOBJ)three_four_five.o \
$(PATHOBJ)rotate_algorithm.o $(PATHOBJ)r_rotate_algorithm.o \
$(PATHOBJ)swap_algorithm.o $(PATHOBJ)rarb_algorithm.o \
$(PATHOBJ)rrarb_algorithm.o $(PATHOBJ)rrarrb_algorithm.o \
$(PATHOBJ)rarb_comp.o $(PATHOBJ)rrarb_comp.o $(PATHOBJ)rrarrb_comp.o \
$(PATHOBJ)rarrb_algorithm.o $(PATHOBJ)rarrb_comp.o \
$(PATHOBJ)prepare_low_stack.o $(PATHOBJ)prepare_big_stack.o $(PATHOBJ)motor.o 

all : $(NAME)

$(NAME)	:
	cd libft && make all && mv libft.a .. && mv $(LIBFTFILESO) ../obj/
	gcc $(FLAGS) -c $(FILESC) && mv $(FILESO) ./obj/
	gcc $(FLAGS) $(ALLOBJ) libft.a -o $(NAME)

clean	:
	rm -Rf libft.a $(ALLOBJ)

fclean : clean
	rm -Rf $(NAME)

re : fclean all