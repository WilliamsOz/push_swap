/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/10/25 23:31:03 by wiozsert         ###   ########.fr       */
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
}					t_data;

typedef struct s_keep
{
	int				first;
	int				mid;
	int				end;
}					t_keep;

typedef struct s_chker
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
}				t_chker;

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

int					ft_strlen(char *str);
int					get_next_line(const int fd, char **line);
void				free_data(t_data **data);
int					ft_strcmp(char *s1, char *s2, int i);
int					ft_isdigit(int c);
int					is_sorted(t_data *stack_a);
int					ft_atoi(const char *nptr);
int					ft_lstsize(t_data *list);

#endif