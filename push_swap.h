/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:30:25 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/23 19:55:57 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL
int counter;
int xd;

#define e exit(EXIT_FAILURE);
	
#define KORG  printf("\033[31;1m");
#define KNRM  printf("\033[0;30m");
#define KRED  printf("\033[0;31m");
#define KGRN  printf("\033[0;32m");
#define KYEL  printf("\033[0;33m");
#define KBLU  printf("\033[0;34m");
#define KMAG  printf("\033[0;35m");
#define KCYN  printf("\033[0;36m");
#define KWHT  printf("\033[0;37m");
#define KSTOP printf("\033[0m");

# include <stdio.h>
void	show_nums(t_data *data, char c);

# define SA show_nums(a, 'A');
# define SB show_nums(b, 'B');
# define D printf("ICI\n");
# define PRINTD(x) printf("%d\n", x);
# define PRINTC(x) printf("%c\n", x);
# define PRINTLD(x) printf("%ld\n", x);
# define PRINTS(x) printf("%s\n", x);
//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL


t_data	*finish_sorting(t_data *a, int size_of_list, int count);
void	sort_stacks(t_data **a, t_data **b, t_data *tmp_a, t_data *tmp_b);
t_data	*sort_big_stacks(t_data *a, t_data *b);
t_data	*prepare_big_stacks(t_data *a, t_data *b, int digits);
t_data	*prepare_low_stacks(t_data *a, t_data *b, int digits);
t_data	*sort_five_digit(t_data *a, t_data *b, int numbers);
t_data	*sort_four_digit(t_data *a, t_data *b, int digits, int count);
t_data	*sort_three_digit(t_data *a, int d_one, int d_two, int d_three);
t_mem	rarrb_cmp(t_mem mem);
t_mem	rrarb_cmp(t_mem mem);
t_mem	rrarrb_cmp(t_mem mem);
t_mem	rarb_cmp(t_mem mem);
void	do_rarrb(t_data **a, t_data **b, t_mem mem);
void	do_rrarb(t_data **a, t_data **b, t_mem mem);
void	do_rrarrb(t_data **a, t_data **b, t_mem mem);
void	do_rarb(t_data **a, t_data **b, t_mem mem);
void	do_rrotate(t_data **a, t_data **b, t_mem mem);
void	do_rotate(t_data **a, t_data **b, t_mem mem);
void	do_swap(t_data **a, t_data **b);
void	sort_stack(t_data **a, t_data **b, t_mem mem);
t_mem	choose_best_algo(t_mem mem);
t_mem	rarrb_check(t_data *a, t_data *b, t_check c, t_mem mem);
t_mem	rrarb_check(t_data *a, t_data *b, t_check c, t_mem mem);
t_mem	rrarrb_check(t_data *a, t_data *b, t_check c, t_mem mem);
t_mem	rarb_check(t_data *a, t_data *b, t_check c, t_mem mem);
t_mem	rrotate_check(t_data *a, t_data *b, t_mem mem);
t_mem	rotate_check(t_data *a, t_data *b, t_mem mem);
t_mem	swap_check(t_data *a, t_data *b, t_mem mem);
t_mem	multiples_check(t_data *a, t_data *b, t_check c, t_mem mem);
t_data	*get_pos_b(t_data *b, t_data *tmp_b, t_check *c);
t_data	*get_new_end(t_data *end, t_data *a);
t_data	*get_end(t_data *a);
void	init_mem(t_mem *mem);
void	init_check(t_check *check);
t_data	*init_position(t_data *stack_a, int numbers, int count);
int		check_errors(int ac, char **av);
void	free_data(t_data **data);
void	rrr(t_data **a, t_data **b);
void	rrab(t_data **data, char c);
void	rr(t_data **a, t_data **b);
void	rab(t_data **data, char c);
void	pb(t_data **a, t_data **b);
void	pa(t_data **a, t_data **b);
void	ss(t_data **stack_a, t_data **stack_b);
void	sab(t_data **data, char c);

#endif
