/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrarb_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:44:14 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/17 11:54:23 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

void	do_rrarb(t_data **a, t_data **b, t_check c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	c.rrarb = 0;
	while (c.rra-- > 0)
		rrab(&tmp_a, 'a');
	while (c.rb-- > 0)
		rab(&tmp_b, 'b');
	pa(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_data	*get_pos_b(t_data *b, t_data *tmp_b, t_check *c)
{
	t_data	*tmp;

	if ((*c).rb == 0)
	{
		(*c).rb += 1;
		tmp = get_end(b);
	}
	else
	{
		(*c).rb += 1;
		tmp = b;
		while (tmp->next != tmp_b)
			tmp = tmp->next;
	}
	return (tmp);
}

t_data	*get_new_end(t_data *end, t_data *a)
{
	t_data	*new_end;

	new_end = a;
	while (new_end->next != end)
		new_end = new_end->next;
	return (new_end);
}

static t_check	apply_modif(t_check c)
{
	c.rra = 0;
	c.count--;
	c.rb++;
	return (c);
}

t_check	rrarb_check(t_data *a, t_data *b, t_check c, int count)
{
	t_data	*end;
	t_data	*tmp_a;

	end = get_end(a);
	tmp_a = a;
	c.count = count;
	while (c.count > 0 && a != NULL && b != NULL)
	{
		while (count > 0 && a != NULL && b != NULL
			&& (b->pos < end->pos || b->pos > tmp_a->pos))
		{
			count--;
			tmp_a = end;
			end = get_new_end(end, a);
			c.rra++;
		}
		if (count > 0)
		{
			c.d_rrarb = 1;
			return (c);
		}
		c = apply_modif(c);
		b = b->next;
	}
	return (c);
}
