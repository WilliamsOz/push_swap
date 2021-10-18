/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:47:50 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/18 10:02:04 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_data	*pre_sort_b(t_data *b, int digits)
{
	digits = (digits / 2) - 1;
	if (b->pos < digits)
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
			rab(&tmp_a, 'a');
	}
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_data	*get_end(t_data *stack)
{
	t_data	*tmp;

	tmp = stack;
	if (stack == NULL)
	{
		tmp = NULL;
		return (tmp);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	init_check(t_check *check)
{
	(*check).rotate_a = 0;
	(*check).rrotate_a = 0;
	(*check).swap_a = 0;
	(*check).do_rarb = 0;
	(*check).rarb = 0;
	(*check).r_a = 0;
	(*check).r_b = 1;
	(*check).do_rrarrb = 0;
	(*check).rrarrb = 0;
	(*check).rr_rra = 0;
	(*check).rr_rrb = 1;
	(*check).do_rrarb = 0;
	(*check).rrarb = 0;
	(*check).rra = 0;
	(*check).rb = 1;
	(*check).do_rarrb = 0;
	(*check).rarrb = 0;
	(*check).ra = 0;
	(*check).rrb = 1;
	(*check).count = 0;
}

t_data	*finish_sorting(t_data *a, int size_of_list, int count)
{
	t_data	*tmp;

	tmp = a;
	if (is_sorted(a) == 1)
		return (a);
	while (tmp->pos != 1)
	{
		tmp = tmp->next;
		count++;
	}
	if (count > (size_of_list / 2))
		while (a->pos != 1)
			rrab(&a, 'a');
	else
		while (a->pos != 1)
			rab(&a, 'a');
	return (a);
}
