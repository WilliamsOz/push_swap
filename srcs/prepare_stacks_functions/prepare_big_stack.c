/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_big_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:51:16 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/25 22:23:06 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	check_pos(int nbr, int digits)
{
	if (nbr == 1 || nbr == (digits * 0.25) || nbr == (digits * 0.5)
		|| nbr == (digits * 0.75) || nbr == digits)
		return (1);
	return (0);
}

static t_data	*pre_sort_a(t_data *a, t_data *b, int digits)
{
	while (ft_lstsize(a) > 3)
	{
		if (a->pos == digits || a->pos == (digits * 0.75))
			pb(&a, &b, 1);
		else
			rab(&a, 'a', 1);
	}
	a = sort_three_digit(a, 0, 0, 0);
	pa(&a, &b, 1);
	pa(&a, &b, 1);
	if (a->pos > a->next->pos)
		sab(&a, 'a', 1);
	rrab(&a, 'a', 1);
	return (a);
}

static t_data	*pre_sort_b(t_data *b, int digits)
{
	if (b->pos < digits * 0.5)
		rab(&b, 'b', 1);
	return (b);
}

t_data	*sort_big_stacks(t_data *a, t_data *b)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = a;
	tmp_b = b;
	sort_stacks(&a, &b, tmp_a, tmp_b);
	return (a);
}

t_data	*prepare_big_stacks(t_data *a, t_data *b, int digits)
{
	t_data	*tmp;
	int		count;

	count = digits - 5;
	a = init_position(a, digits, 1);
	while (count > 0)
	{
		tmp = a;
		if (check_pos(tmp->pos, digits) == 1)
		{
			rab(&a, 'a', 1);
			tmp = tmp->next;
		}
		else
		{
			pb(&a, &b, 1);
			if (ft_lstsize(b) > 2)
				b = pre_sort_b(b, digits);
			count--;
		}
	}
	a = pre_sort_a(a, b, digits);
	a = sort_big_stacks(a, b);
	return (a);
}
