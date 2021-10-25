/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:53:46 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/25 23:33:15 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sab(t_data **data, char c, int ind)
{
	t_data	*tmp;
	t_data	*keep;

	if (*data != NULL && (*data)->next != NULL)
	{
		tmp = (*data)->next;
		keep = tmp->next;
		tmp->next = (*data);
		(*data)->next = keep;
		*data = tmp;
		if (c == 'a')
		{
			if (ind == 1)
				write(1, "sa\n", 3);
		}
		else if (c == 'b')
		{
			if (ind == 1)
				write(1, "sb\n", 3);
		}
	}
}

void	ss(t_data **stack_a, t_data **stack_b, int ind)
{
	sab(stack_a, '\0', 1);
	sab(stack_b, '\0', 1);
	if (ind == 1)
		write(1, "ss\n", 3);
}
