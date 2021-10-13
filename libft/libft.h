/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/10/13 17:20:57 by wiozsert         ###   ########.fr       */
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
	int				d_rrarb;
	int				rrarb;
	int				rra;
	int				rb;
	int				d_rotate;
	int				d_a;
	int				d_b;
	int				d_r;
	int				count;
}				t_check;

int					ft_isdigit(int c);
int					is_sorted(t_data *stack_a);
int					ft_atoi(const char *nptr);
int					ft_lstsize(t_data *list);

#endif