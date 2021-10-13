/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_rotate_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:18:59 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/13 13:31:06 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_check	get_d_r(t_check c)
{
	int	tmp_da;
	int	tmp_db;

	tmp_da = c.d_a;
	tmp_db = c.d_b;
	while (tmp_da > 0 && tmp_db > 0)
	{
		c.d_r++;
		tmp_da--;
		tmp_db--;
	}
	c.d_r = c.d_r + tmp_da + tmp_db;
	return (c);
}

void	do_drotate(t_data **a, t_data **b, t_check c)
{
	xd++;
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	PRINTD(c.rotate_a)
	PRINTD(c.rrotate_a)
	PRINTD(c.d_a)
	PRINTD(c.d_b)
	PRINTD(c.d_r)
	c.d_r = 0;
	show_nums(*a, 'a');
	show_nums(*b, 'b');
	while (c.d_a > 0 && c.d_b > 0)
	{
		c.d_r++;
		c.d_a--;
		c.d_b--;
	}
	while (c.d_r-- > 0)
		rr(&tmp_a, &tmp_b);
	while (c.d_a-- > 0)
		rab(&tmp_a, 'a');
	while (c.d_b-- > 0)
		rab(&tmp_b, 'b');
	pa(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
	// show_nums(*a, 'a');
	// show_nums(*b, 'b');
	if (xd == 4)
		exit (EXIT_FAILURE);
}

t_check	d_rotate_check(t_data *a, t_data *b, t_check c, int count)
{
	t_data	*end;
	int		save;

	end = get_end(a);
	b = b->next;
	save = count;
	c.d_a = 0;
	c.d_b++;
	while (save > 0 && a != NULL && b != NULL)
	{
		while (b->pos < end->pos || b->pos > a->pos)
		{
			c.d_a++;
			end = a;
			a = a->next;
		}
		if (count == 0 && save > 0)
			c = d_rotate_check(a, b, c, save - 1);
		if (count > 0)
		{
			c.d_rotate = 1;
			return (c);
		}
	}
	return (c);
}
