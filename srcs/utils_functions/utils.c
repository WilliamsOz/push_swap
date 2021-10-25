/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:47:50 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/25 19:55:57 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_data	*get_new_end(t_data *end, t_data *a)
{
	t_data	*new_end;

	new_end = a;
	while (new_end->next != end)
		new_end = new_end->next;
	return (new_end);
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

void	init_mem(t_mem *mem)
{
	(*mem).swap = 0;
	(*mem).rotate_a = 0;
	(*mem).rrotate_a = 0;
	(*mem).do_rarb = 0;
	(*mem).rarb = 0;
	(*mem).r_a = 0;
	(*mem).r_b = 1;
	(*mem).do_rrarrb = 0;
	(*mem).rrarrb = 0;
	(*mem).rr_rra = 0;
	(*mem).rr_rrb = 1;
	(*mem).do_rrarb = 0;
	(*mem).rrarb = 0;
	(*mem).rra = 0;
	(*mem).rb = 1;
	(*mem).do_rarrb = 0;
	(*mem).rarrb = 0;
	(*mem).ra = 0;
	(*mem).rrb = 1;
}

void	init_check(t_check *check)
{
	(*check).rotate_a = 0;
	(*check).rrotate_a = 0;
	(*check).rarb = 0;
	(*check).r_a = 0;
	(*check).r_b = 1;
	(*check).rrarrb = 0;
	(*check).rr_rra = 0;
	(*check).rr_rrb = 1;
	(*check).rrarb = 0;
	(*check).rra = 0;
	(*check).rb = 1;
	(*check).rarrb = 0;
	(*check).ra = 0;
	(*check).rrb = 1;
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
			rrab(&a, 'a', 1);
	else
		while (a->pos != 1)
			rab(&a, 'a', 1);
	return (a);
}
