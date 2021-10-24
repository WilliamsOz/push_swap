/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:41:14 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/24 23:20:23 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void		sort_stack(t_data **a, t_data **b, t_mem mem)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	if (mem.swap > 0)
		do_swap(&tmp_a, &tmp_b);
	else if (mem.do_rarb == 1)
		do_rarb(&tmp_a, &tmp_b, mem);
	else if (mem.do_rrarrb == 1)
		do_rrarrb(&tmp_a, &tmp_b, mem);
	else if (mem.do_rrarb == 1)
		do_rrarb(&tmp_a, &tmp_b, mem);
	else if (mem.do_rarrb == 1)
		do_rarrb(&tmp_a, &tmp_b, mem);
	else if (mem.rotate_a <= mem.rrotate_a)
		do_rotate(&tmp_a, &tmp_b, mem);
	else if (mem.rrotate_a < mem.rotate_a)
		do_rrotate(&tmp_a, &tmp_b, mem);
	else
		rab(&tmp_a, 'a');
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_mem		choose_best_algo(t_mem mem)
{
	if (mem.do_rarb == 1)
		mem = rarb_cmp(mem);
	if (mem.do_rrarrb == 1)
		mem = rrarrb_cmp(mem);
	if (mem.do_rrarb == 1)
		mem = rrarb_cmp(mem);
	if (mem.do_rarrb == 1)
		mem = rarrb_cmp(mem);
	return (mem);
}

t_mem		multiples_check(t_data *a, t_data *b, t_check c, t_mem mem)
{
	mem = swap_check(a, b, mem);
	mem = rotate_check(a, b, mem);
	mem = rrotate_check(a, b, mem);
	mem = rarb_check(a, b->next, c, mem);
	mem = rrarrb_check(a, b, c, mem);
	mem = rrarb_check(a, b->next, c, mem);
	mem = rarrb_check(a, b, c, mem);
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
		end = get_end(*a);
		if (tmp_b->pos < tmp_a->pos && tmp_b->pos > end->pos)
			pa(&tmp_a, &tmp_b);
		else
		{
			init_check(&c);
			mem = multiples_check(tmp_a, tmp_b, c, mem);
			mem = choose_best_algo(mem);
			sort_stack(&tmp_a, &tmp_b, mem);
		}
		(*a) = tmp_a;
		(*b) = tmp_b;
	}
	(*a) = finish_sorting(tmp_a, ft_lstsize(*a), 1);
	//DELETE
	// PRINTD(xd)
	// show_nums(*a, 'a');
	// show_nums(*b, 'b');
	// e
	//STOP
}

//verifier si la fonction rr_algorithm ne marche pas ou est inutile
//verifier si la fonction rrr_algorithm ne marche pas ou est inutile
