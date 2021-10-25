/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrarb_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:44:14 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/25 23:23:32 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	do_rrarb(t_data **a, t_data **b, t_mem mem)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	while (mem.rra-- > 0)
		rrab(&tmp_a, 'a', 1);
	while (mem.rb-- > 0)
		rab(&tmp_b, 'b', 1);
	pa(&tmp_a, &tmp_b, 1);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_mem	memorise_rrarb(t_check c, t_mem mem)
{
	c.rrarb = c.rra + c.rb;
	if (mem.rrarb == 0)
	{
		mem.do_rrarb = 1;
		mem.rrarb = c.rrarb;
		mem.rra = c.rra;
		mem.rb = c.rb;
	}
	else if (mem.rrarb > c.rrarb)
	{
		mem.rrarb = c.rrarb;
		mem.rra = c.rra;
		mem.rb = c.rb;
	}
	return (mem);
}

t_mem	rrarb_check(t_data *a, t_data *b, t_check c, t_mem mem)
{
	t_data	*tmp_a;
	t_data	*end;

	tmp_a = a;
	end = get_end(a);
	while (b != NULL)
	{
		while (a != end && (b->pos < end->pos || b->pos > tmp_a->pos))
		{
			tmp_a = end;
			end = get_new_end(end, a);
			c.rra++;
		}
		if (a != end && b->pos > end->pos && b->pos < tmp_a->pos)
			mem = memorise_rrarb(c, mem);
		tmp_a = a;
		end = get_end(a);
		b = b->next;
		c.rb++;
	}
	return (mem);
}
