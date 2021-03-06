/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:36:11 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/19 11:41:52 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_data	*get_position(t_data *stack_a, int numbers, int count)
{
	t_data	*tmp;
	t_data	*keep;

	while (count <= numbers)
	{
		tmp = stack_a;
		while (tmp->pos != -1)
			tmp = tmp->next;
		keep = tmp;
		while (tmp != NULL)
		{
			if (tmp->pos == -1 && tmp->nbr < keep->nbr)
				keep = tmp;
			tmp = tmp->next;
		}
		keep->pos = count;
		count++;
	}
	return (stack_a);
}

t_data	*init_position(t_data *stack_a, int numbers, int count)
{
	t_data	*tmp;

	tmp = stack_a;
	while (tmp != NULL)
	{
		tmp->pos = -1;
		tmp = tmp->next;
	}
	stack_a = get_position(stack_a, numbers, count);
	return (stack_a);
}
