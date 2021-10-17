/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:41:48 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/17 11:54:41 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

t_check	rotate_check(t_data *a, t_data *b, t_check c)
{
	t_data	*tmp;

	tmp = a;
	while (tmp != NULL && b->pos < tmp->pos)
	{
		c.rotate_a += 1;
		tmp = tmp->next;
	}
	while (tmp != NULL && b->pos > tmp->pos)
	{
		c.rotate_a += 1;
		tmp = tmp->next;
	}
	return (c);
}

void	do_rotate(t_data **a, t_data **b, t_check c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	while (c.rotate_a > 0)
	{
		rab(&tmp_a, 'a');
		c.rotate_a--;
	}
	pa(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
}
