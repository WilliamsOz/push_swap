/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_algo_to_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:09:34 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/19 19:39:30 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_check		multiples_check(t_data *a, t_data *b, t_check c, int count)
{
	c = rotate_check(a, b, c);
	c = rrotate_check(a, b, c);
	if (c.rotate_a <= c.rrotate_a)
		c.do_rotate_a = 1;
	else if (c.rotate_a > c.rrotate_a)
		c.do_rrotate_a = 1;
	c = swap_check(a, b, c);
	count = c.rotate_a;
	if (c.rrotate_a < count)
		count = c.rrotate_a;
	c.count = count;
	c = rarb_check(a, b->next, c, count - 1);
	c.count = count;
	c = rrarrb_check(a, b, c, count - 1);
	c.count = count;
	c = rrarb_check(a, b->next, c, count - 1);
	c.count = count;
	c = rarrb_check(a, b->next, c, count - 1);
	c = o_rr_check(a, b, c, count);
	c = o_rrr_check(a, b, c, count);
	return (c);
}

t_check		get_all_move(t_check c)
{
	if (c.do_rarb == 1)
		c = get_rarb(c);
	if (c.do_rrarrb == 1)
		c = get_rrarrb(c);
	if (c.do_rrarb == 1)
		c.rrarb = c.rb + c.rra;
	if (c.do_rarrb == 1)
		c = get_rarrb(c);
	c = rarb_cmp(c);
	c = rrarrb_cmp(c);
	c = rrarb_cmp(c);
	c = rarrb_cmp(c);
	c = rr_cmp(c);
	PRINTD(c.do_rrotate_a)
	c = rrr_cmp(c);
	// PRINTD(c.rotate_a)
	// PRINTD(c.rrotate_a)
	// PRINTD(c.rarb)
	// PRINTD(c.rrarrb)
	// PRINTD(c.rarrb)
	// PRINTD(c.rrarb)
	// PRINTD(c.o_rr)
	// PRINTD(c.o_rrr)
	// PRINTD(c.swap_a)
	return (c);
}

void		sort_with_algo(t_data **a, t_data **b, t_check c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	if (c.swap_a == 2)
		do_swap(&tmp_a, &tmp_b);
	else if (c.do_rarb == 1)
		do_rarb(&tmp_a, &tmp_b, c);
	else if (c.do_rrarrb == 1)
		do_rrarrb(&tmp_a, &tmp_b, c);
	else if (c.do_rrarb == 1)
		do_rrarb(&tmp_a, &tmp_b, c);
	else if (c.do_rarrb == 1)
		do_rarrb(&tmp_a, &tmp_b, c);
	else if (c.do_rr == 1)
		do_rr(&tmp_a, &tmp_b, c);
	else if (c.do_rrr == 1)
		do_rrr(&tmp_a, &tmp_b, c);
	else if (c.do_rotate_a == 1)
		do_rotate(&tmp_a, &tmp_b, c);
	else if (c.do_rrotate_a == 1)
		do_rrotate(&tmp_a, &tmp_b, c);
	(*a) = tmp_a;
	(*b) = tmp_b;
}
