/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:41:14 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/19 19:41:22 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_check		optimise_for_ls(t_check c, t_data *b)
{
	(void)b;
	// if (ft_lstsize(b) < 3)
	// {
		// c.algo_are_optimal = 1;
		// return (c);
	// }
	if (c.do_rotate_a == 1 && c.rotate_a <= 15)
		c.algo_are_optimal = 1;
	else if (c.do_rrotate_a == 1 && c.do_rrotate_a <= 15)
		c.algo_are_optimal = 1;
	else if (c.do_rarb == 1 && c.do_rarb <= 15)
		c.algo_are_optimal = 1;
	else if (c.do_rrarrb == 1 && c.rrarrb <= 15)
		c.algo_are_optimal = 1;
	else if (c.do_rarrb == 1 && c.rarrb <= 15)
		c.algo_are_optimal = 1;
	else if (c.do_rrarb == 1 && c.rrarb <= 15)
		c.algo_are_optimal = 1;
	else if (c.do_rr == 1 && c.o_rr <= 15)
		c.algo_are_optimal = 1;
	else if (c.do_rrr == 1 && c.o_rrr <= 15)
		c.algo_are_optimal = 1;
	return (c);
}

void		choose_best_move(t_data **a, t_data **b, t_check c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	if (ft_lstsize(tmp_a) + ft_lstsize(tmp_b) < 250)
		c = optimise_for_ls(c, tmp_b);
	// else
		// optimise_for_bs(c);
	if (c.algo_are_optimal == 1)
		sort_with_algo(&tmp_a, &tmp_b, c);
	else
	{
		show_nums(*b, 'b');
		rab(&tmp_b, 'b');
	}
	(*a) = tmp_a;
	(*b) = tmp_b;
}
 
void		sort_stacks(t_data **a, t_data **b, t_data *tmp_a, t_data *tmp_b)
{
	t_data	*end;
	t_check	c;
	
	while (ft_lstsize(*b) > 0)
	{
		// show_nums(*a, 'a');
		// show_nums(*b, 'b');
		end = get_end(*a);
		if (tmp_b->pos < tmp_a->pos && tmp_b->pos > end->pos)
			pa(&tmp_a, &tmp_b);
		else
		{
			init_check(&c);
			c = multiples_check(tmp_a, tmp_b, c, 0);
			c = get_all_move(c);
			choose_best_move(&tmp_a, &tmp_b, c);
		}
		(*a) = tmp_a;
		(*b) = tmp_b;
	}
	(*a) = finish_sorting(tmp_a, ft_lstsize(*a), 1);
	//DELETE
	// show_nums(*a, 'a');
	// show_nums(*b, 'b');
	// e
	//STOP
}
