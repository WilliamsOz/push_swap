/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:41:14 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/20 12:33:36 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// if (ft_lstsize(tmp_a) + ft_lstsize(tmp_b) < 250)
		// c = optimise_for_ls(c, tmp_b);
	// else
		// optimise_for_bs(c);
	// if (c.algo_are_optimal == 1)
// else
	// {
		// show_nums(*b, 'b');
		// rab(&tmp_b, 'b');
	// }
// t_check		optimise_for_ls(t_check c, t_data *b)
// {
// 	(void)b;
// 	// if (ft_lstsize(b) < 3)
// 	// {
// 		// c.algo_are_optimal = 1;
// 		// return (c);
// 	// }
// 	if (c.do_rotate_a == 1 && c.rotate_a <= 15)
// 		c.algo_are_optimal = 1;
// 	else if (c.do_rrotate_a == 1 && c.do_rrotate_a <= 15)
// 		c.algo_are_optimal = 1;
// 	else if (c.do_rarb == 1 && c.do_rarb <= 15)
// 		c.algo_are_optimal = 1;
// 	else if (c.do_rrarrb == 1 && c.rrarrb <= 15)
// 		c.algo_are_optimal = 1;
// 	else if (c.do_rarrb == 1 && c.rarrb <= 15)
// 		c.algo_are_optimal = 1;
// 	else if (c.do_rrarb == 1 && c.rrarb <= 15)
// 		c.algo_are_optimal = 1;
// 	else if (c.do_rr == 1 && c.o_rr <= 15)
// 		c.algo_are_optimal = 1;
// 	else if (c.do_rrr == 1 && c.o_rrr <= 15)
// 		c.algo_are_optimal = 1;
// 	return (c);
// }

void		sort_with_algo(t_data **a, t_data **b, t_mem mem)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	if (mem.swap > 0)
		do_swap(&tmp_a, &tmp_b);
	else if (mem.rotate_a > 0)
		do_rotate(&tmp_a, &tmp_b, mem);
	else if (mem.rrotate_a > 0)
		do_rrotate(&tmp_a, &tmp_b, mem);
	else if (mem.rarb > 0)
	{
		do_rarb(a, b, mem);
		e
	}


	// else if (c.do_rrarrb == 1)
	// 	do_rrarrb(&tmp_a, &tmp_b, c);
	// else if (c.do_rrarb == 1)
	// 	do_rrarb(&tmp_a, &tmp_b, c);
	// else if (c.do_rarrb == 1)
	// 	do_rarrb(&tmp_a, &tmp_b, c);

	(*a) = tmp_a;
	(*b) = tmp_b;
}

// void		choose_best_move(t_data **a, t_data **b, t_mem mem)
// {
// 	t_data	*tmp_a;
// 	t_data	*tmp_b;

// 	tmp_a = (*a);
// 	tmp_b = (*b);
// 	sort_with_algo(&tmp_a, &tmp_b, mem);
// 	(*a) = tmp_a;
// 	(*b) = tmp_b;
// }

t_mem		multiples_check(t_data *a, t_data *b, t_check c, t_mem mem)
{
	mem = rotate_check(a, b, c, mem);
	mem = rrotate_check(a, b, c, mem);
	mem = o_rr_check(a, b, c, mem);
	mem = o_rrr_check(a, b, c, mem);
	mem = rarb_check(a, b->next, c, mem);


	// c = rrarrb_check(a, b, c, count - 1);
	// c = rrarb_check(a, b->next, c, count - 1);
	// c = rarrb_check(a, b, c, count - 1);
	return (mem);
}

void		sort_stacks(t_data **a, t_data **b, t_data *tmp_a, t_data *tmp_b)
{
	t_mem	mem;
	t_data	*end;
	t_check	c;
	
	while (ft_lstsize(*b) > 0)
	{
		init_mem(&mem);
		// show_nums(*a, 'a');
		// show_nums(*b, 'b');
		end = get_end(*a);
		if (tmp_b->pos < tmp_a->pos && tmp_b->pos > end->pos)
			pa(&tmp_a, &tmp_b);
		else
		{
			init_check(&c);
			mem = multiples_check(tmp_a, tmp_b, c, mem);
			mem = get_all_move(mem);
			// choose_best_move(&tmp_a, &tmp_b, mem);
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
