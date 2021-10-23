/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_big_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:51:16 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/23 19:56:04 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	check_pos(int nbr, int digits, int f_digits)
{
	f_digits /= 2;
	f_digits *= 1.5;
	if (nbr == 1 || nbr == digits || nbr == (digits / 2) ||
		nbr == ((digits / 2) / 2) || nbr == f_digits)
		return (1);
	return (0);
}

static t_data	*pre_sort_a(t_data *a, t_data *b, int l_digits, int f_digits)
{
	f_digits = f_digits / 2;
	f_digits *= 1.5;
	while (ft_lstsize(a) > 3)
	{
		if (a->pos == l_digits || a->pos == f_digits)
			pb(&a, &b);
		else
			rab(&a, 'a');
	}
	a = sort_three_digit(a, 0, 0, 0);
	pa(&a, &b);
	pa(&a, &b);
	if (a->pos > a->next->pos)
		sab(&a, 'a');
	return (a);
}

static t_data	*pre_sort_b(t_data *b, int digits)
{
	if (b->pos < digits * 0.5)
		rab(&b, 'b');
	if (b->next->pos < b->pos)
		sab(&b, 'b');
	return (b);
}

t_data	*sort_big_stacks(t_data *a, t_data *b)
{
	t_data *tmp_a;
	t_data *tmp_b;
	
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
	tmp = a;
	a = init_position(a, digits, 1);
	while (count > 0)
	{
		tmp = a;
		if (check_pos(tmp->pos, digits, digits) == 1)
		{
			rab(&a, 'a');
			tmp = tmp->next;
		}
		else
		{
			pb(&a, &b);
			if (ft_lstsize(b) > 2)
				b = pre_sort_b(b, digits);
			count--;
		}
	}
	a = pre_sort_a(a, b, digits, digits);
	SB
	SA
	e
	a = sort_big_stacks(a, b);
	return (a);
}
