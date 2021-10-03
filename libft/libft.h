/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/09/22 15:24:53 by wiozsert         ###   ########.fr       */
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

int					ft_isdigit(int c);
int					lk_ascending_order_check(t_data *stack_a);
int					ft_atoi(const char *nptr);
int					ft_lstsize(t_data *list);

#endif