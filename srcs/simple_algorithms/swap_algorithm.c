/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:32:46 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/18 11:52:50 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	do_swap(t_data **a, t_data **b)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	pa(&tmp_a, &tmp_b);
	sab(&tmp_a, 'a');
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_check	swap_check(t_data *a, t_data *b, t_check c)
{
	if (b->pos > a->pos && b->pos < a->next->pos)
		c.swap_a = 2;
	else
		c.swap_a = -1;
	return (c);
}
