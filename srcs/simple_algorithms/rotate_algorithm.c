/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:41:48 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/20 12:16:57 by wiozsert         ###   ########.fr       */
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
		rab(&tmp_a, 'a');
		mem.rotate_a--;
	}
	pa(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_mem	rotate_check(t_data *a, t_data *b, t_check c, t_mem mem)
{
	t_data	*tmp;

	tmp = a;
	while (tmp != NULL && b->pos < tmp->pos)
	{
		c.rotate_a += 1;
		tmp = tmp->next;
	}
	while (tmp != NULL && b->pos > tmp->pos)
	{
		c.rotate_a += 1;
		tmp = tmp->next;
	}
	mem.rotate_a = c.rotate_a;
	return (mem);
}
