/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:25:14 by user42            #+#    #+#             */
/*   Updated: 2021/10/26 17:38:31 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_data	*reverse_rotate(t_data *data)
{
	t_data	*tmp;
	t_data	*keep;

	if (data != NULL && data->next != NULL)
	{
		tmp = data;
		while (tmp->next != NULL)
			tmp = tmp->next;
		keep = data;
		while (keep->next != tmp)
			keep = keep->next;
		tmp->next = data;
		keep->next = NULL;
		data = tmp;
	}
	return (data);
}

void	rrab(t_data **data, char c, int ind)
{
	if (c == 'a')
	{
		*data = reverse_rotate(*data);
		if (ind == 1)
			write(1, "rra\n", 4);
	}
	else if (c == 'b')
	{
		*data = reverse_rotate(*data);
		if (ind == 1)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_data **a, t_data **b, int ind)
{
	*a = reverse_rotate(*a);
	*b = reverse_rotate(*b);
	if (ind == 1)
		write(1, "rrr\n", 4);
}
