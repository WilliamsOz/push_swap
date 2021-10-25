/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lk_ascending_order_check.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:16:23 by user42            #+#    #+#             */
/*   Updated: 2021/10/25 21:38:03 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	is_sorted(t_data *stack_a)
{
	t_data	*keep;
	t_data	*tmp;

	keep = stack_a;
	while (keep->next != NULL)
	{
		tmp = keep->next;
		while (tmp != NULL)
		{
			if (keep->nbr > tmp->nbr)
				return (0);
			else
				tmp = tmp->next;
		}
		keep = keep->next;
	}
	return (1);
}
