/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrarrb_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:53:44 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/23 15:47:19 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_mem	rrarrb_complex_algo_cmp(t_mem mem)
{
	if (mem.do_rarb == 1 && mem.rrarrb >= mem.rarb)
		mem.do_rrarrb = 0;
	else if (mem.do_rarb == 1 && mem.rrarrb < mem.rarb)
		mem.do_rarb = 0;
	return (mem);
}

static t_mem	rrarrb_basic_algo_cmp(t_mem mem)
{
	if (mem.rrarrb >= mem.rotate_a)
		mem.do_rrarrb = 0;
	if (mem.rrarrb >= mem.rrotate_a)
		mem.do_rrarrb = 0;
	if (mem.do_rr == 1 && mem.rrarrb <= mem.rr)
		mem.do_rr = 0;
	else if (mem.do_rr == 1 && mem.rrarrb > mem.rr)
		mem.do_rrarrb = 0;
	if (mem.do_rrr == 1 && mem.rrarrb <= mem.rrr)
		mem.do_rrr = 0;
	else if (mem.do_rrr == 1 && mem.rrarrb > mem.rrr)
		mem.do_rrarrb = 0;
	return (mem);
}

t_mem	rrarrb_cmp(t_mem mem)
{
	if (mem.swap == 1)
		mem.do_rrarrb = 0;
	if (mem.do_rrarrb == 1)
		mem = rrarrb_basic_algo_cmp(mem);
	if (mem.do_rrarrb == 1)
		mem = rrarrb_complex_algo_cmp(mem);
	return (mem);
}
