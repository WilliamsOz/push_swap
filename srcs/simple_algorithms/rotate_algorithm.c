/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:41:48 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/25 19:53:07 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	do_rotate(t_data **a, t_data **b, t_mem mem)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	while (mem.rotate_a > 0)
	{
		rab(&tmp_a, 'a', 1);
		mem.rotate_a--;
	}
	pa(&tmp_a, &tmp_b, 1);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_mem	rotate_check(t_data *a, t_data *b, t_mem mem)
{
	t_data	*end;

	end = get_end(a);
	while (b->pos > a->pos || b->pos < end->pos)
	{
		end = a;
		a = a->next;
		mem.rotate_a++;
	}
	return (mem);
}
