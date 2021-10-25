/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rarrb_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:49:28 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/25 19:53:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	do_rarrb(t_data **a, t_data **b, t_mem mem)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	while (mem.ra-- > 0)
		rab(&tmp_a, 'a', 1);
	while (mem.rrb-- > 0)
		rrab(&tmp_b, 'b', 1);
	pa(&tmp_a, &tmp_b, 1);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_mem	memorise_rarrb(t_check c, t_mem mem)
{
	c.rarrb = c.ra + c.rrb;
	if (mem.rarrb == 0)
	{
		mem.do_rarrb = 1;
		mem.rarrb = c.rarrb;
		mem.ra = c.ra;
		mem.rrb = c.rrb;
	}
	else if (mem.rarrb > c.rarrb)
	{
		mem.rarrb = c.rarrb;
		mem.ra = c.ra;
		mem.rrb = c.rrb;
	}
	return (mem);
}

t_mem	rarrb_check(t_data *a, t_data *b, t_check c, t_mem mem)
{
	t_data	*tmp_a;
	t_data	*tmp_b;
	t_data	*end;

	tmp_a = a;
	tmp_b = get_end(b);
	end = get_end(a);
	while (b != tmp_b)
	{
		while (tmp_a != NULL
			&& (tmp_b->pos < end->pos || tmp_b->pos > tmp_a->pos))
		{
			end = tmp_a;
			tmp_a = tmp_a->next;
			c.ra++;
		}
		if (tmp_a != NULL && end != NULL && tmp_b->pos > end->pos && tmp_b->pos < tmp_a->pos)
			mem = memorise_rarrb(c, mem);
		tmp_a = a;
		end = get_end(a);
		tmp_b = get_new_end(tmp_b, b);
		c.ra = 0;
		c.rrb++;
	}
	return (mem);
}
