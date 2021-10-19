/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:52:25 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/19 19:40:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_check	rr_complex_algo_cmp(t_check c)
{
	if (c.do_rr == 1 && c.o_rr < c.rarb && c.do_rarb == 1)
		c.do_rarb = 0;
	else if (c.do_rr == 1 && c.o_rr > c.rarb && c.do_rarb == 1)
		c.do_rr = 0;
	if (c.do_rr == 1 && c.o_rr < c.rrarrb && c.do_rrarrb == 1)
		c.do_rrarrb = 0;
	else if (c.do_rr == 1 && c.o_rr > c.rrarrb && c.do_rrarrb == 1)
		c.do_rr = 0;
	if (c.do_rr == 1 && c.o_rr < c.rarrb && c.do_rarrb == 1)
		c.do_rarrb = 0;
	else if (c.do_rr == 1 && c.o_rr > c.rarrb && c.do_rarrb == 1)
		c.do_rr = 0;
	if (c.do_rr == 1 && c.o_rr < c.rrarb && c.do_rrarb == 1)
		c.do_rrarb = 0;
	else if (c.do_rr == 1 && c.o_rr > c.rrarb && c.do_rrarb == 1)
		c.do_rr = 0;
	if (c.do_rr == 1 && c.o_rr < c.o_rrr && c.o_rrr == 1)
		c.do_rrr = 0;
	else if (c.do_rr == 1 && c.o_rr > c.o_rrr && c.o_rrr == 1)
		c.do_rr = 0;
		return (c);
}

static t_check	rr_simple_algo_cmp(t_check c)
{
	if (c.swap_a == 2)
	{
		if (c.o_rr < c.swap_a)
			c.swap_a = -1;
		else if (c.swap_a <= c.o_rr)
			c.do_rr = 0;
	}
	else if (c.do_rotate_a == 1)
	{
		if (c.o_rr < c.rotate_a)
			c.do_rotate_a = 0;
		else if (c.o_rr >= c.rotate_a)
			c.do_rr = 0;
	}
	else if (c.do_rrotate_a == 1)
	{
		if (c.o_rr < c.rrotate_a)
			c.do_rrotate_a = 0;
		else if (c.o_rr >= c.rrotate_a)
			c.do_rr = 0;
	}
	return (c);
}

t_check		rr_cmp(t_check c)
{
	if (c.do_rr == 1)
	{
		c = rr_simple_algo_cmp(c);
		c = rr_complex_algo_cmp(c);	
	}
	return (c);
}

void	do_rr(t_data **a, t_data **b, t_check c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	while (c.o_rr > 0)
	{
		rr(&tmp_a, &tmp_b);
		c.o_rr--;
	}
	pa(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_check		o_rr_check(t_data *a, t_data *b, t_check c, int count)
{
	t_data	*end;

	end = get_end(a);
	while (count > 0 && a != NULL && b != NULL
		&& (b->pos < end->pos || b->pos > a->pos))
	{
		count--;
		c.o_rr++;
		end = a;
		a = a->next;
		b = b->next;
	}
	if (count > 0 && b != NULL && a != NULL)
	{
		c.do_rr = 1;
		return (c);
	}
	return (c);
}
