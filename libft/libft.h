/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/10/25 15:06:46 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "./get_next_line.h"


//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL
# include <stdio.h>
# define SA show_nums(a, 'A');
# define SB show_nums(b, 'B');
# define D printf("ICI\n");
# define PRINTD(x) printf("%d\n", x);
# define PRINTC(x) printf("%c\n", x);
# define PRINTLD(x) printf("%ld\n", x);
# define PRINTS(x) printf("%s\n", x);
//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

typedef struct s_data
{
	struct s_data	*next;
	int				nbr;
	int				pos;
}					t_data;

typedef struct s_keep
{
	int				first;
	int				mid;
	int				end;
}					t_keep;

typedef struct s_bskeep
{
	int				d1;
	int				d3;
	int				d4;
	int				d5;
	int				d6;
	int				d7;
}					t_bskeep;

typedef struct s_checker
{
	char			*sa;
	int				do_sa;
	char			*sb;
	int				do_sb;
	char			*ss;
	int				do_ss;
	char			*pa;
	int				do_pa;
	char			*pb;
	int				do_pb;
	char			*ra;
	int				do_ra;
	char			*rb;
	int				do_rb;
	char			*rr;
	int				do_rr;
	char			*rra;
	int				do_rra;
	char			*rrb;
	int				do_rrb;
	char			*rrr;
	int				do_rrr;
}				t_checker;

typedef struct s_check
{
	int				swap_a;
	int				rotate_a;
	int				rrotate_a;
	int				rarb;
	int				r_a;
	int				r_b;
	int				rrarrb;
	int				rr_rra;
	int				rr_rrb;
	int				rrarb;
	int				rra;
	int				rb;
	int				rarrb;
	int				ra;
	int				rrb;
}					t_check;

typedef struct s_mem
{
	int				swap;
	int				rotate_a;
	int				rrotate_a;
	int				do_rarb;
	int				rarb;
	int				r_a;
	int				r_b;
	int				do_rrarrb;
	int				rrarrb;
	int				rr_rra;
	int				rr_rrb;
	int				do_rrarb;
	int				rrarb;
	int				rra;
	int				rb;
	int				do_rarrb;
	int				rarrb;
	int				ra;
	int				rrb;
}					t_mem;

void				free_data(t_data **data);
int					ft_strcmp(char *s1, char *s2, int i);
int					ft_isdigit(int c);
int					is_sorted(t_data *stack_a);
int					ft_atoi(const char *nptr);
int					ft_lstsize(t_data *list);

#endif