/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lk_ascending_order_checker.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:16:23 by user42            #+#    #+#             */
/*   Updated: 2021/06/14 20:18:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	lk_ascending_order_check(t_data *stack_a)
{
	t_data	*keep;
	t_data	*tmp;

	keep = stack_a;
	while (keep->next != NULL)
	{
		tmp = keep->next;
		if (tmp->nbr < keep->nbr)
			return (NOT_SORTED);
		else
			keep = keep->next;
	}
	return (SORTED);
}
