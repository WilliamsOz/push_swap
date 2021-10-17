/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rarrb_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:49:28 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/17 16:53:57 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	do_rarrb(t_data **a, t_data **b, t_check c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	while (c.ra-- > 0)
		rab(&tmp_a, 'a');
	while (c.rrb-- > 0)
		rrab(&tmp_b, 'b');
	pa(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_check	get_rarrb(t_check c)
{
	int	tmp_a;
	int	tmp_b;

	tmp_a = c.ra;
	tmp_b = c.rrb;
	while (tmp_a > 0 && tmp_b > 0)
	{
		c.rarrb++;
		tmp_a--;
		tmp_b--;
	}
	c.rarrb = c.rarrb + tmp_a + tmp_b;
	return (c);
}

static t_check	apply_modif(t_check c)
{
	c.rrb++;
	c.ra = 0;
	c.count--;
	return (c);
}

t_check	rarrb_check(t_data *a, t_data *b, t_check c, int count)
{
	t_data	*tmp_b;
	t_data	*end;

	tmp_b = get_end(b);
	end = get_end(a);
	while (c.count > 0 && a != NULL && tmp_b != b)
	{
		while (count > 0 && a != NULL && tmp_b != b
			&& (tmp_b->pos < end->pos || tmp_b->pos > a->pos))
		{
			count--;
			end = a;
			a = a->next;
			c.ra++;
		}
		if (count > 0)
		{
			c.do_rarrb = 1;
			return (c);
		}
		c = apply_modif(c);
		tmp_b = get_new_end(tmp_b, b);
	}
	return (c);
}
