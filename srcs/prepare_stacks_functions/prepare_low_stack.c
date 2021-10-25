/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_low_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:37:24 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/25 19:54:33 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_data	*pre_sort_b(t_data *b, int digits)
{
	digits = (digits / 2) - 1;
	if (b->pos < digits)
		rab(&b, 'b', 1);
	return (b);
}

static void	divide_stack(t_data **a, t_data **b, t_keep keep, int digits)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	while (ft_lstsize(tmp_a) != 3)
	{
		if (tmp_a->pos != keep.first && tmp_a->pos != keep.mid
			&& tmp_a->pos != keep.end)
		{
			pb(&tmp_a, &tmp_b, 1);
			if (ft_lstsize(tmp_b) > 1)
				tmp_b = pre_sort_b(tmp_b, digits);
		}
		else
			rab(&tmp_a, 'a', 1);
	}
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_data	*prepare_low_stacks(t_data *a, t_data *b, int digits)
{
	t_keep	keep;
	t_data	*tmp_a;
	t_data	*tmp_b;

	a = init_position(a, digits, 1);
	keep.first = 1;
	keep.mid = ft_lstsize(a) / 2;
	keep.end = ft_lstsize(a);
	divide_stack(&a, &b, keep, digits);
	if (is_sorted(a) == 0)
		a = sort_three_digit(a, 0, 0, 0);
	tmp_a = a;
	tmp_b = b;
	sort_stacks(&a, &b, tmp_a, tmp_b);
	return (a);
}
