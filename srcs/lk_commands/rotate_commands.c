/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:05:40 by user42            #+#    #+#             */
/*   Updated: 2021/10/25 23:33:11 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_data	*rotate(t_data *data)
{
	t_data	*tmp;
	t_data	*last;

	if (data != NULL)
	{
		tmp = data->next;
		last = data;
		while (last->next != NULL)
			last = last->next;
		last->next = data;
		data->next = NULL;
		data = tmp;
	}
	return (data);
}

void	rab(t_data **data, char c, int ind)
{
	if (c == 'a')
	{
		*data = rotate(*data);
		if (ind == 1)
			write(1, "ra\n", 3);
	}
	else if (c == 'b')
	{
		*data = rotate(*data);
		if (ind == 1)
			write(1, "rb\n", 3);
	}
}

void	rr(t_data **a, t_data **b, int ind)
{
	*a = rotate(*a);
	*b = rotate(*b);
	if (ind == 1)
		write(1, "rr\n", 3);
}
