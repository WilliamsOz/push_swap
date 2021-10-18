/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lk_ascending_order_check.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:16:23 by user42            #+#    #+#             */
/*   Updated: 2021/10/18 12:53:53 by wiozsert         ###   ########.fr       */
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
		if (tmp->nbr < keep->nbr)
			return (0);
		else
			keep = keep->next;
	}
	return (1);
}
