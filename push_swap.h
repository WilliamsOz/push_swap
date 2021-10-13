/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:30:25 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/13 10:20:49 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
// # include <libc.h>
# include <stdio.h>
# include "./libft/libft.h"

int counter;
int xd;
	
#define KNRM  printf("\033[0;30m");
#define KRED  printf("\033[0;31m");
#define KGRN  printf("\033[0;32m");
#define KYEL  printf("\033[0;33m");
#define KBLU  printf("\033[0;34m");
#define KMAG  printf("\033[0;35m");
#define KCYN  printf("\033[0;36m");
#define KWHT  printf("\033[0;37m");
#define KSTOP printf("\033[0m");

// int main()
// {
//     printf("%sred\n", KRED);
//     printf("%sgreen\n", KGRN);
//     printf("%syellow\n", KYEL);
//     printf("%sblue\n", KBLU);
//     printf("%smagenta\n", KMAG);
//     printf("%scyan\n", KCYN);
//     printf("%swhite\n", KWHT);
//     printf("%snormal\n", KNRM);

//     return 0;
// }

# define SA show_nums(a, 'A');
# define SB show_nums(b, 'B');
# define DEBUG printf("ICI\n");
# define PRINTD(x) printf("%d\n", x);
# define PRINTC(x) printf("%c\n", x);
# define PRINTLD(x) printf("%ld\n", x);
# define PRINTS(x) printf("%s\n", x);

void	show_nums(t_data *data, char c);

t_check	get_d_rr(t_check c);
void	do_drotate(t_data **a, t_data **b, t_check c);
t_check	d_rotate_check(t_data *a, t_data *b, t_check c, int count);
t_data	*finish_sorting(t_data *a, int size_of_list, int count);
void	do_swap(t_data **a, t_data **b);
t_check	swap_check(t_data *a, t_data *b, t_check c);
t_data	*pre_sort_b(t_data *b, int digits);
void	divide_stack(t_data **a, t_data **b, t_keep keep, int digits);
t_data	*get_end(t_data *a);
void	init_check(t_check *check);
void	do_rrotate(t_data **a, t_data **b, t_check c);
t_check	rrotate_check(t_data *a, t_data *b, t_check c);
void	do_rotate(t_data **a, t_data **b, t_check c);
t_check	rotate_check(t_data *a, t_data *b, t_check c);
t_data	*sort_three_digit(t_data *a, int d_one, int d_two, int d_three);
t_data	*sort_four_digit(t_data *a, t_data *b, int digits, int count);
t_data	*sort_five_digit(t_data *a, t_data *b, int numbers);
t_data	*get_pivot(t_data *stack_a, t_data *pivot, int numbers);
int		get_max_pos(t_data *a);
t_data	*init_ind(t_data *data);
t_data	*init_position(t_data *stack_a, int numbers, int count);
void	free_data(t_data **data);
void	rrr(t_data **a, t_data **b);
void	rrab(t_data **data, char c);
void	rr(t_data **a, t_data **b);
void	rab(t_data **data, char c);
void	pb(t_data **a, t_data **b);
void	pa(t_data **a, t_data **b);
void	ss(t_data **stack_a, t_data **stack_b);
void	sab(t_data **data, char c);
int		check_errors(int ac, char **av);

#endif
