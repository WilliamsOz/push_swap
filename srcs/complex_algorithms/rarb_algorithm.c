/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rarb_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:18:59 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/18 11:50:15 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_check	get_rarb(t_check c)
{
	int	tmp_da;
	int	tmp_db;

	tmp_da = c.r_a;
	tmp_db = c.r_b;
	while (tmp_da > 0 && tmp_db > 0)
	{
		c.rarb++;
		tmp_da--;
		tmp_db--;
	}
	c.rarb = c.rarb + tmp_da + tmp_db;
	return (c);
}

void	do_rarb(t_data **a, t_data **b, t_check c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	c.rarb = 0;
	while (c.r_a > 0 && c.r_b > 0)
	{
		c.rarb++;
		c.r_a--;
		c.r_b--;
	}
	while (c.rarb-- > 0)
		rr(&tmp_a, &tmp_b);
	while (c.r_a-- > 0)
		rab(&tmp_a, 'a');
	while (c.r_b-- > 0)
		rab(&tmp_b, 'b');
	pa(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_check	rarb_check(t_data *a, t_data *b, t_check c, int count)
{
	t_data	*end;

	end = get_end(a);
	while (c.count > 0 && a != NULL && b != NULL)
	{
		while (count > 0 && a != NULL && b != NULL
			&& (b->pos < end->pos || b->pos > a->pos))
		{
			count--;
			end = a;
			a = a->next;
			c.r_a++;
		}
		if (count > 0)
		{
			c.do_rarb = 1;
			return (c);
		}
		c.r_a = 0;
		c.count--;
		c.r_b++;
		b = b->next;
	}
	return (c);
}
