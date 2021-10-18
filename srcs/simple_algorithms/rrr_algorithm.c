/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:22:49 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/18 18:53:25 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_check		rrr_cmp(t_check c)
{
	if (c.do_rrr == 1 && c.o_rrr >= c.swap_a && c.swap_a == 2)
		c.o_rrr = 0;
	if (c.do_rrr == 1 && c.o_rrr < c.rarb && c.do_rarb == 1)
		c.do_rarb = 0;
	else if (c.do_rrr == 1 && c.o_rrr > c.rarb && c.do_rarb == 1)
		c.do_rrr = 0;
	if (c.do_rrr == 1 && c.o_rrr < c.rrarrb && c.do_rrarrb == 1)
		c.do_rrarrb = 0;
	else if (c.do_rrr == 1 && c.o_rrr > c.rrarrb && c.do_rrarrb == 1)
		c.do_rrr = 0;
	if (c.do_rrr == 1 && c.o_rrr < c.rarrb && c.do_rarrb == 1)
		c.do_rarrb = 0;
	else if (c.do_rrr == 1 && c.o_rrr > c.rarrb && c.do_rarrb == 1)
		c.do_rrr = 0;
	if (c.do_rrr == 1 && c.o_rrr < c.rrarb && c.do_rrarb == 1)
		c.do_rrarb = 0;
	else if (c.do_rrr == 1 && c.o_rrr > c.rrarb && c.do_rrarb == 1)
		c.do_rrr = 0;
	if (c.do_rrr == 1 && c.o_rrr < c.o_rr && c.o_rr == 1)
		c.do_rr = 0;
	else if (c.do_rrr == 1 && c.o_rrr > c.o_rr && c.o_rr == 1)
		c.do_rrr = 0;
	return (c);
}

void	do_rrr(t_data **a, t_data **b, t_check c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	while (c.o_rrr > 0)
	{
		rrr(&tmp_a, &tmp_b);
		c.o_rrr--;
	}
	pa(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_check		o_rrr_check(t_data *a, t_data *b, t_check c, int count)
{
	t_data	*tmp_a;
	t_data	*tmp_b;
	t_data	*end;
	
	tmp_a = a;
	tmp_b = b;
	end = get_end(a);
	while (count > 0 && a->next != end && b->next != tmp_b
		&& (tmp_b->pos < end->pos || tmp_b->pos > tmp_a->pos))
	{
		count--;
		c.o_rrr++;
		tmp_a = end;
		end = get_new_end(end, a);
		if (tmp_b == b)
			tmp_b = get_end(tmp_b);
		else
			tmp_b = get_new_end(tmp_b, b);
	}
	if (count > 0 && tmp_b != b && end != a && b->next != tmp_b)
	{
		c.do_rrr = 1;
		return (c);
	}
	return (c);
}
