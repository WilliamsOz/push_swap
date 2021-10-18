/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/10/18 12:19:22 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define SORTED 1
# define NOT_SORTED 0

# include <string.h>
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

typedef struct s_check
{
	int				rotate_a;
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
	int				count;
}				t_check;

int					ft_isdigit(int c);
int					is_sorted(t_data *stack_a);
int					ft_atoi(const char *nptr);
int					ft_lstsize(t_data *list);

#endif