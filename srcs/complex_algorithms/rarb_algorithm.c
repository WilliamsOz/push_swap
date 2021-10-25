/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rarb_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:18:59 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/25 23:21:00 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	do_rarb(t_data **a, t_data **b, t_mem mem)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	while (mem.r_a > 0 && mem.r_b > 0)
	{
		mem.r_a--;
		mem.r_b--;
		rr(&tmp_a, &tmp_b, 1);
	}
	while (mem.r_a-- > 0)
		rab(&tmp_a, 'a', 1);
	while (mem.r_b-- > 0)
		rab(&tmp_b, 'b', 1);
	pa(&tmp_a, &tmp_b, 1);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

static t_mem	memorise_rarb(t_check c, t_mem mem, int tmp_ra, int tmp_rb)
{
	while (tmp_ra > 0 && tmp_rb > 0)
	{
		tmp_ra--;
		tmp_rb--;
		c.rarb++;
	}
	c.rarb = c.rarb + tmp_ra + tmp_rb;
	if (mem.rarb == 0)
	{
		mem.do_rarb = 1;
		mem.rarb = c.rarb;
		mem.r_a = c.r_a;
		mem.r_b = c.r_b;
	}
	else if (mem.rarb > c.rarb)
	{
		mem.rarb = c.rarb;
		mem.r_a = c.r_a;
		mem.r_b = c.r_b;
	}
	return (mem);
}

t_mem	rarb_check(t_data *a, t_data *b, t_check c, t_mem mem)
{
	t_data	*tmp_a;
	t_data	*end;

	end = get_end(a);
	tmp_a = a;
	while (b != NULL)
	{
		while (tmp_a != NULL && (b->pos < end->pos || b->pos > tmp_a->pos))
		{
			end = tmp_a;
			tmp_a = tmp_a->next;
			c.r_a++;
		}
		if (tmp_a != NULL && b->pos > end->pos && b->pos < tmp_a->pos)
			mem = memorise_rarb(c, mem, c.r_a, c.r_b);
		tmp_a = a;
		end = get_end(a);
		c.r_a = 0;
		b = b->next;
		c.r_b++;
	}
	return (mem);
}
