/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:30:25 by wiozsert          #+#    #+#             */
/*   Updated: 2021/09/09 17:53:59 by wiozsert         ###   ########.fr       */
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

# define SA show_nums(stack_a, 'A');
# define SB show_nums(stack_b, 'B');
# define DEBUG printf("ICI\n");
# define PRINTD(x) printf("%d\n", x);
# define PRINTC(x) printf("%c\n", x);
# define PRINTLD(x) printf("%ld\n", x);
# define PRINTS(x) printf("%s\n", x);

void	show_nums(t_data *data, char c);

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
