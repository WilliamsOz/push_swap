/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:45:19 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/20 17:52:33 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	do_rrotate(t_data **a, t_data **b, t_mem mem)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	show_nums(*a, 'a');
	while (mem.rrotate_a > 0)
	{
		rrab(&tmp_a, 'a');
		mem.rrotate_a--;
	}
	pa(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_mem	rrotate_check(t_data *a, t_data *b, t_mem mem)
{
	t_data	*end;
	t_data	*tmp_a;

	tmp_a = a;
	end = get_end(a);
	while (b->pos > tmp_a->pos || b->pos < end->pos)
	{
		mem.rrotate_a++;
		tmp_a = end;
		end = get_new_end(end, a);
	}
	return (mem);
}
