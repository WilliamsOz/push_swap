/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:22:49 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/20 11:55:26 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// static t_check	rrr_complex_algo_cmp(t_check c)
// {
// 	if (c.do_rrr == 1 && c.o_rrr < c.rarb && c.do_rarb == 1)
// 		c.do_rarb = 0;
// 	else if (c.do_rrr == 1 && c.o_rrr > c.rarb && c.do_rarb == 1)
// 		c.do_rrr = 0;
// 	if (c.do_rrr == 1 && c.o_rrr < c.rrarrb && c.do_rrarrb == 1)
// 		c.do_rrarrb = 0;
// 	else if (c.do_rrr == 1 && c.o_rrr > c.rrarrb && c.do_rrarrb == 1)
// 		c.do_rrr = 0;
// 	if (c.do_rrr == 1 && c.o_rrr < c.rarrb && c.do_rarrb == 1)
// 		c.do_rarrb = 0;
// 	else if (c.do_rrr == 1 && c.o_rrr > c.rarrb && c.do_rarrb == 1)
// 		c.do_rrr = 0;
// 	if (c.do_rrr == 1 && c.o_rrr < c.rrarb && c.do_rrarb == 1)
// 		c.do_rrarb = 0;
// 	else if (c.do_rrr == 1 && c.o_rrr > c.rrarb && c.do_rrarb == 1)
// 		c.do_rrr = 0;
// 	if (c.do_rrr == 1 && c.o_rrr < c.o_rr && c.o_rr == 1)
// 		c.do_rr = 0;
// 	else if (c.do_rrr == 1 && c.o_rrr > c.o_rr && c.o_rr == 1)
// 		c.do_rrr = 0;
// 	return (c);
// }

static t_mem	rrr_simple_algo_cmp(t_mem mem)
{
	if (mem.swap == 1)
		mem.rrr = 0;
	if (mem.rrr < mem.rotate_a)
		mem.rotate_a = 0;
	else if (mem.rrr >= mem.rotate_a)
		mem.rrr = 0;
	if (mem.rrr < mem.rrotate_a)
		mem.rrotate_a = 0;
	else if (mem.rrr >= mem.rrotate_a)
		mem.rrr = 0;
	return (mem);
}

t_mem	rrr_cmp(t_mem mem)
{
	if (mem.rrr > 0)
	{
		mem = rrr_simple_algo_cmp(mem);
		// mem = rrr_complex_algo_cmp(mem);	
	}
	return (mem);
}

void	do_rrr(t_data **a, t_data **b, t_mem mem)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	while (mem.rrr > 0)
	{
		rrr(&tmp_a, &tmp_b);
		mem.rrr--;
	}
	pa(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_mem		o_rrr_check(t_data *a, t_data *b, t_check c, t_mem mem)
{
	t_data	*tmp_a;
	t_data	*tmp_b;
	t_data	*end;
	
	tmp_a = a;
	tmp_b = b;
	end = get_end(a);
	// while (a->next != end && b->next != tmp_b
	while (a != end && b != tmp_b && end != NULL && tmp_b != NULL
		&& (tmp_b->pos < end->pos || tmp_b->pos > tmp_a->pos))
	{
		c.o_rrr++;
		tmp_a = end;
		end = get_new_end(end, a);
		if (tmp_b == b)
			tmp_b = get_end(tmp_b);
		else
			tmp_b = get_new_end(tmp_b, b);
	}
	if (tmp_b->pos > end->pos && tmp_b->pos < tmp_a->pos)
		mem.rrr = c.o_rrr;
	return (mem);
}
