/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:47:50 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/12 10:52:39 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_data	*pre_sort_b(t_data *b, int digits)
{
	digits = (digits / 2) - 1;
	if (b->pos > digits)
		rab(&b, 'b');
	return (b);
}

void	divide_stack(t_data **a, t_data **b, t_keep keep, int digits)
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
			pb(&tmp_a, &tmp_b);
			if (ft_lstsize(tmp_b) > 1 && digits < 250)
				tmp_b = pre_sort_b(tmp_b, digits);
		}
		else
			rrab(&tmp_a, 'a');
	}
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_data	*get_end(t_data *a)
{
	t_data	*tmp;

	tmp = a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	init_check(t_check *check)
{
	(*check).rotate_a = 0;
	(*check).rrotate_a = 0;
	(*check).rotate_b = 0;
	(*check).rr = 0;
}

int	is_a_correct(t_data *a)
{
	int	f;
	int	s;
	int	t;

	f = a->pos;
	s = a->next->pos;
	t = a->next->next->pos;
	if ((s > f && s > t) || (t > f && t > s) || (f > s && f > t))
		return (0);
	return (1);
}
