/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrarrb_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:28:49 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/17 16:14:11 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

t_check	get_rrarrb(t_check c)
{
	int		tmp_a;
	int		tmp_b;

	tmp_a = c.rr_rra;
	tmp_b = c.rr_rrb;
	while (tmp_a > 0 && tmp_b > 0)
	{
		c.rrarrb++;
		tmp_a--;
		tmp_b--;
	}
	c.rrarrb = c.rrarrb + tmp_a + tmp_b;
	return (c);
}

static t_check	apply_modif_for_b_for_rrarrb(t_check c)
{
	c.rr_rra = 0;
	c.count--;
	c.rr_rrb++;
	return (c);
}

static t_check	apply_modif_for_a_for_rrarrb(t_check c, int *ptr_count)
{
	*ptr_count -= 1;
	c.rr_rra++;
	return (c);
}

t_check	rrarrb_check(t_data *a, t_data *b, t_check c, int count)
{
	t_data	*tmp_a;
	t_data	*tmp_b;
	t_data	*end;

	tmp_a = a;
	end = get_end(a);
	tmp_b = get_end(b);
	while (c.count > 0 && end != a && tmp_b != b)
	{
		while (count > 0 && tmp_a != end && tmp_b != b
			&& (tmp_b->pos < end->pos || tmp_b->pos > tmp_a->pos))
		{
			c = apply_modif_for_a_for_rrarrb(c, &count);
			tmp_a = end;
			end = get_new_end(end, a);
		}
		if (count > 0)
		{
			c.do_rrarrb = 1;
			return (c);
		}
		c = apply_modif_for_b_for_rrarrb(c);
		tmp_b = get_new_end(tmp_b, b);
	}
	return (c);
}

void	do_rrarrb(t_data **a, t_data **b, t_check c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	c.rrarrb = 0;
	while (c.rr_rra > 0 && c.rr_rrb > 0)
	{
		c.rrarrb++;
		c.rr_rra--;
		c.rr_rrb--;
	}
	while (c.rrarrb-- > 0)
		rrr(&tmp_a, &tmp_b);
	while (c.rr_rra-- > 0)
		rrab(&tmp_a, 'a');
	while (c.rr_rrb-- > 0)
		rrab(&tmp_b, 'b');
	pa(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
}
