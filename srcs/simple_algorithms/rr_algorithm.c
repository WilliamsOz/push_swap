/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:52:25 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/20 12:17:17 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_mem	rr_simple_algo_cmp(t_mem mem)
{
	if (mem.swap == 1)
		mem.rr = 0;
	if (mem.rr < mem.rotate_a && mem.rr != -1)
		mem.rotate_a = 0;
	else if (mem.rr >= mem.rotate_a)
		mem.rr = 0;
	if (mem.rr < mem.rrotate_a && mem.rr != -1)
		mem.rrotate_a = 0;
	else if (mem.rr >= mem.rrotate_a)
		mem.rr = 0;
	return (mem);
}

t_mem		rr_cmp(t_mem mem)
{
	if (mem.rr > 0)
		mem = rr_simple_algo_cmp(mem);
	return (mem);
}

void	do_rr(t_data **a, t_data **b, t_mem mem)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	while (mem.rr > 0)
	{
		rr(&tmp_a, &tmp_b);
		mem.rr--;
	}
	pa(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_mem		o_rr_check(t_data *a, t_data *b, t_check c, t_mem mem)
{
	t_data	*end;

	end = get_end(a);
	while (a != NULL && b != NULL && (b->pos < end->pos || b->pos > a->pos))
	{
		c.o_rr++;
		end = a;
		a = a->next;
		b = b->next;
	}
	if (b->pos > end->pos && b->pos < a->pos)
		mem.rr = c.o_rr;
	return (mem);
}
