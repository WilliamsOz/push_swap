/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:05:40 by user42            #+#    #+#             */
/*   Updated: 2021/06/15 11:35:36 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_data   *rotate(t_data *data)
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

void	rab(t_data **data, char c)
{
	if (c == 'a')
	{
		*data = rotate(*data);
		write(1, "ra\n", 3);
		counter++;
	}
	else if (c == 'b')
	{
		*data = rotate(*data);
		write(1, "rb\n", 3);
		counter++;
	}
}

void	rr(t_data **a, t_data **b)
{
	*a = rotate(*a);
	*b = rotate(*b);
	counter += 2;
	write(1, "rr\n", 3);
}
