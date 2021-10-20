/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:32:46 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/20 11:12:07 by wiozsert         ###   ########.fr       */
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

t_mem	swap_check(t_data *a, t_data *b, t_mem mem)
{
	if (b->pos > a->pos && b->pos < a->next->pos)
		mem.swap = 1;
	else
		mem.swap = 0;
	return (mem);
}
