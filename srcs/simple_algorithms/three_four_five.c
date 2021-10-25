/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_four_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 13:05:57 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/25 19:54:56 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_data	*sort_three_digit(t_data *a, int d_one, int d_two, int d_three)
{
	d_one = a->nbr;
	d_two = a->next->nbr;
	d_three = a->next->next->nbr;
	if (d_one > d_two && d_two > d_three)
	{
		sab(&a, 'a', 1);
		rrab(&a, 'a', 1);
	}
	else if (d_one < d_two && d_three < d_one)
		rrab(&a, 'a', 1);
	else if (d_two > d_three && d_three > d_one)
	{
		rrab(&a, 'a', 1);
		sab(&a, 'a', 1);
	}
	else if (d_one > d_two && d_three > d_one)
		sab(&a, 'a', 1);
	else if (d_one > d_three && d_three > d_two)
		rab(&a, 'a', 1);
	return (a);
}

t_data	*sort_four_digit(t_data *a, t_data *b, int digits, int count)
{
	t_data	*tmp;

	a = init_position(a, digits, 1);
	tmp = a;
	while (tmp->pos != 1)
	{
		tmp = tmp->next;
		count++;
	}
	if (count > 2)
		while (a->pos != 1)
			rrab(&a, 'a', 1);
	else
		while (a->pos != 1)
			rab(&a, 'a', 1);
	pb(&a, &b, 1);
	a = sort_three_digit(a, 0, 0, 0);
	pa(&a, &b, 1);
	return (a);
}

static t_data	*find_pos(t_data *a, int numbers, int position, int count)
{
	t_data	*tmp;

	tmp = a;
	while (tmp->pos != position)
	{
		tmp = tmp->next;
		count++;
	}
	if (count > numbers / 2)
		while (a->pos != position)
			rrab(&a, 'a', 1);
	else
		while (a->pos != position)
			rab(&a, 'a', 1);
	return (a);
}

t_data	*sort_five_digit(t_data *a, t_data *b, int numbers)
{
	a = init_position(a, numbers, 1);
	a = find_pos(a, numbers, 1, 0);
	pb(&a, &b, 1);
	a = find_pos(a, numbers, 2, 0);
	pb(&a, &b, 1);
	a = sort_three_digit(a, 0, 0, 0);
	pa(&a, &b, 1);
	pa(&a, &b, 1);
	return (a);
}
