/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rarrb_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:52:41 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/23 17:34:47 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_mem	rarrb_complex_algo_cmp(t_mem mem)
{
	if (mem.do_rarb == 1 && mem.rarrb >= mem.rarb)
		mem.do_rarrb = 0;
	else if (mem.do_rarb == 1 && mem.rarrb < mem.rarb)
		mem.do_rarb = 0;
	if (mem.do_rrarrb == 1 && mem.rarrb >= mem.rrarrb)
		mem.do_rarrb = 0;
	else if (mem.do_rrarrb == 1 && mem.rarrb < mem.rrarrb)
		mem.do_rrarrb = 0;
	if (mem.do_rrarb == 1 && mem.rarrb >= mem.rrarb)
		mem.do_rarrb = 0;
	else if (mem.do_rrarb == 1 && mem.rarrb < mem.rrarb)
		mem.do_rrarb = 0;
	return (mem);
}

static t_mem	rarrb_basic_algo_cmp(t_mem mem)
{
	if (mem.rarrb >= mem.rotate_a)
		mem.do_rarrb = 0;
	if (mem.rarrb >= mem.rrotate_a)
		mem.do_rarrb = 0;
	if (mem.do_rr == 1 && mem.rarrb <= mem.rr)
		mem.do_rr = 0;
	else if (mem.do_rr == 1 && mem.rarrb > mem.rr)
		mem.do_rarrb = 0;
	if (mem.do_rrr == 1 && mem.rarrb <= mem.rrr)
		mem.do_rrr = 0;
	else if (mem.do_rrr == 1 && mem.rarrb > mem.rrr)
		mem.do_rarrb = 0;
	return (mem);
}

t_mem	rarrb_cmp(t_mem mem)
{
	if (mem.swap == 1)
		mem.do_rarrb = 0;
	if (mem.do_rarrb == 1)
		mem = rarrb_basic_algo_cmp(mem);
	if (mem.do_rarrb == 1)
		mem = rarrb_complex_algo_cmp(mem);
	return (mem);
}
