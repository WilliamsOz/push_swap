/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:41:14 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/18 12:41:02 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_check		sort_best_move(t_check c)
{
	if (c.do_rarb == 1)
		c = get_rarb(c);
	if (c.do_rrarb == 1)
		c.rrarb = c.rb + c.rra;
	if (c.do_rrarrb == 1)
		c = get_rrarrb(c);
	if (c.do_rarrb == 1)
		c = get_rarrb(c);
	PRINTD(c.rotate_a)
	PRINTD(c.rrotate_a)
	PRINTD(c.rarb)
	PRINTD(c.rrarb)
	PRINTD(c.rrarrb)
	PRINTD(c.rarrb)
	c = rarb_cmp(c);
	c = rrarrb_cmp(c);
	c = rrarb_cmp(c);
	c = rarrb_cmp(c);
	printf("\ncc\n");
	PRINTD(c.do_rarb)
	PRINTD(c.do_rrarb)
	PRINTD(c.do_rrarrb)
	PRINTD(c.do_rarrb)
	return (c);
}

void		choose_best_move(t_data **a, t_data **b, t_check c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	c = sort_best_move(c);
	if (c.swap_a == 2)
		do_swap(&tmp_a, &tmp_b);
	else if (c.do_rarb == 1)
		do_rarb(&tmp_a, &tmp_b, c);
	else if (c.do_rrarrb == 1)
		do_rrarrb(&tmp_a, &tmp_b, c);
	else if (c.do_rrarb == 1)
		do_rrarb(&tmp_a, &tmp_b, c);
	else if (c.do_rarrb == 1)
		do_rarrb(&tmp_a, &tmp_b, c);
	else if (c.rotate_a <= c.rrotate_a)
		do_rotate(&tmp_a, &tmp_b, c);
	else if (c.rrotate_a < c.rotate_a)
		do_rrotate(&tmp_a, &tmp_b, c);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_check		multiples_check(t_data *a, t_data *b, t_check c, int count)
{
	c = rotate_check(a, b, c);
	c = rrotate_check(a, b, c);
	c = swap_check(a, b, c);
	count = c.rotate_a;
	if (c.rrotate_a < count)
		count = c.rrotate_a;
	c.count = count;
	if (c.swap_a == -1 && count > 0)
		c = rarb_check(a, b->next, c, count - 1);
	c.count = count;
	if (c.swap_a == -1 && count > 0)
		c = rrarrb_check(a, b, c, count - 1);
	c.count = count;
	if (c.swap_a == -1 && count > 0)
		c = rrarb_check(a, b->next, c, count - 1);
	c.count = count;
	if (c.swap_a == -1 && count > 0)
		c = rarrb_check(a, b->next, c, count - 1);
	return (c);
}

void		sort_stacks(t_data **a, t_data **b, t_data *tmp_a, t_data *tmp_b)
{
	t_data	*end;
	t_check	c;
	
	while (ft_lstsize(*b) > 0)
	{
		end = get_end(*a);
		if (tmp_b->pos < tmp_a->pos && tmp_b->pos > end->pos)
			pa(&tmp_a, &tmp_b);
		else
		{
			init_check(&c);
			c = multiples_check(tmp_a, tmp_b, c, 0);
			choose_best_move(&tmp_a, &tmp_b, c);
		}
		(*a) = tmp_a;
		(*b) = tmp_b;
	}
	(*a) = finish_sorting(tmp_a, ft_lstsize(*a), 1);
	//DELETE
	// show_nums(*a, 'a');
	// show_nums(*b, 'b');
	// exit (EXIT_FAILURE);
	//STOP
}
