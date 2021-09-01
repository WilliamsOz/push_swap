/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:12:43 by wiozsert          #+#    #+#             */
/*   Updated: 2021/09/01 18:14:24 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_data	*treat_three(t_data *stack_a, int a, int b, int c)
{
	a = stack_a->nbr;
	b = stack_a->next->nbr;
	c = stack_a->next->next->nbr;

	if (a > b && b > c && a > c)
	{
		stack_a = sab(stack_a, 'a');
		rrab(&stack_a, 'a');
	}
	else if (a < b && b > c && c < a)
		rrab(&stack_a, 'a');
	else if (a < b && b > c && b > a)
	{
		rrab(&stack_a, 'a');
		stack_a = sab(stack_a, 'a');
	}
	else if (a > b && b < c && c < a)
		rab(&stack_a, 'a');
	else
		stack_a = sab(stack_a, 'a');
	return (stack_a);
}
