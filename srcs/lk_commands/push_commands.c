/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:01:52 by user42            #+#    #+#             */
/*   Updated: 2021/06/15 11:35:28 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_data **a, t_data **b) //b ver a
{
	t_data	*tmp;

	if (*b != NULL)
	{
		tmp = (*b)->next;
		(*b)->next = (*a);
		(*a) = (*b);
		(*b) = tmp;
	}
	write(1, "pa\n", 3);
	counter++;
}

void	pb(t_data **a, t_data **b)
{
	t_data	*tmp;

	if (*a != NULL)
	{
		tmp = (*a)->next;
		(*a)->next = (*b);
		(*b) = (*a);
		(*a) = tmp;
	}
	write(1, "pb\n", 3);
	counter++;
}
