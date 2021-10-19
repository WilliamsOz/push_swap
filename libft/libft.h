/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/10/19 18:20:18 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	struct s_data	*next;
	int				nbr;
	int				pos;
}				t_data;

typedef struct s_keep
{
	int				first;
	int				mid;
	int				end;
}				t_keep;

typedef struct s_bskeep
{
	int				d1;
	int				d3;
	int				d4;
	int				d5;
	int				d6;
	int				d7;
}				t_bskeep;

typedef struct s_check
{
	int				do_rotate_a;
	int				rotate_a;
	int				do_rrotate_a;
	int				rrotate_a;
	int				swap_a;
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
	int				do_rr;
	int				o_rr;
	int				do_rrr;
	int				o_rrr;
	int				count;
	int				algo_are_optimal;
}				t_check;

int					ft_isdigit(int c);
int					is_sorted(t_data *stack_a);
int					ft_atoi(const char *nptr);
int					ft_lstsize(t_data *list);

#endif