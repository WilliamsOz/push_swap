/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrarb_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:00:46 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/23 19:52:45 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_mem	rrarb_complex_algo_cmp(t_mem mem)
{
	if (mem.do_rarb == 1 && mem.rrarb >= mem.rarb)
		mem.do_rrarb = 0;
	else if (mem.do_rarb == 1 && mem.rrarb < mem.rarb)
		mem.do_rarb = 0;
	if (mem.do_rrarrb == 1 && mem.rrarb >= mem.rrarrb)
		mem.do_rrarb = 0;
	else if (mem.do_rrarrb == 1 && mem.rrarb < mem.rrarrb)
		mem.do_rrarrb = 0;
	return (mem);
}

t_mem	rrarb_basic_algo_cmp(t_mem mem)
{
	if (mem.rrarb >= mem.rotate_a)
		mem.do_rrarb = 0;
	if (mem.rrarb >= mem.rrotate_a)
		mem.do_rrarb = 0;
	return (mem);
}

t_mem	rrarb_cmp(t_mem mem)
{
	if (mem.swap == 1)
		mem.do_rrarb = 0;
	if (mem.do_rrarb == 1)
		mem = rrarb_basic_algo_cmp(mem);
	if (mem.do_rrarb == 1)
		mem = rrarb_complex_algo_cmp(mem);
	return (mem);
}
