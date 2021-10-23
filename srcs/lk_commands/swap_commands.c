/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:53:46 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/23 16:54:38 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sab(t_data **data, char c)
{
	t_data	*tmp;
	t_data	*keep;

	if (*data != NULL)
	{
		tmp = (*data)->next;
		keep = tmp->next;
		tmp->next = (*data);
		(*data)->next = keep;
		*data = tmp;
		if (c == 'a')
		{
			write(1, "sa\n", 3);
			counter++;
		}
		else if (c == 'b')
		{
			write(1, "sb\n", 3);
			counter++;
		}
	}
}

void	ss(t_data **stack_a, t_data **stack_b)
{
	sab(stack_a, '\0');
	sab(stack_b, '\0');
	write(1, "ss\n", 3);
	counter++;
}
