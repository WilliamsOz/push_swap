/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrarrb_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:28:49 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/25 19:51:52 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	do_rrarrb(t_data **a, t_data **b, t_mem mem)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	while (mem.rr_rra > 0 && mem.rr_rrb > 0)
	{
		mem.rr_rra--;
		mem.rr_rrb--;
		rrr(&tmp_a, &tmp_b, 1);
	}
	while (mem.rr_rra-- > 0)
		rrab(&tmp_a, 'a', 1);
	while (mem.rr_rrb-- > 0)
		rrab(&tmp_b, 'b', 1);
	pa(&tmp_a, &tmp_b, 1);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

static t_mem	memorise_rrarrb(t_check c, t_mem mem, int tmp_rra, int tmp_rrb)
{
	while (tmp_rra > 0 && tmp_rrb > 0)
	{
		tmp_rra--;
		tmp_rrb--;
		c.rrarrb++;
	}
	c.rrarrb = c.rrarrb + tmp_rra + tmp_rrb;
	if (mem.rrarrb == 0)
	{
		mem.do_rrarrb = 1;
		mem.rrarrb = c.rrarrb;
		mem.rr_rra = c.rr_rra;
		mem.rr_rrb = c.rr_rrb;
	}
	else if (mem.rrarrb > c.rrarrb)
	{
		mem.rrarrb = c.rrarrb;
		mem.rr_rra = c.rr_rra;
		mem.rr_rrb = c.rr_rrb;
	}
	return (mem);
}

t_mem	rrarrb_check(t_data *a, t_data *b, t_check c, t_mem mem)
{
	t_data	*tmp_a;
	t_data	*tmp_b;
	t_data	*end;

	tmp_a = a;
	end = get_end(a);
	tmp_b = get_end(b);
	while (b != tmp_b)
	{
		while (a != end
			&& (tmp_b->pos < end->pos || tmp_b->pos > tmp_a->pos))
		{
			tmp_a = end;
			end = get_new_end(end, a);
			c.rr_rra++;
		}
		if (a != end && tmp_b->pos > end->pos && tmp_b->pos < tmp_a->pos)
			mem = memorise_rrarrb(c, mem, c.rr_rra, c.rr_rrb);
		tmp_a = a;
		end = get_end(a);
		tmp_b = get_new_end(tmp_b, b);
		c.rr_rra = 0;
		c.rr_rrb++;
	}
	return (mem);
}
