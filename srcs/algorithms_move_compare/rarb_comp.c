/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rarb_comp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:30:21 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/20 12:22:42 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// static t_check	rarb_rrarrb_cmp(t_check c)
// {
// 	if (c.rarb < c.rrarrb)
// 		c.do_rrarrb = 0;
// 	else if (c.rrarrb < c.rarb)
// 		c.do_rarb = 0;
// 	return (c);
// }

// static t_check	rarb_rrarb_cmp(t_check c)
// {
// 	if (c.rarb < c.rrarb)
// 		c.do_rrarb = 0;
// 	else if (c.rrarb < c.rarb)
// 		c.do_rarb = 0;
// 	return (c);
// }

// static t_check	rarb_rarrb_cmp(t_check c)
// {
// 	if (c.rarb < c.rarrb)
// 		c.do_rarrb = 0;
// 	else if (c.rarrb < c.rarb)
// 		c.do_rarb = 0;
// 	return (c);
// }

static t_mem	rarb_basics_algo_cmp(t_mem mem)
{
	
	if (mem.rarb < mem.rotate_a)
		mem.rotate_a = 0;
	else if (mem.rarb >= mem.rotate_a)
		mem.rarb = 0;
	if (mem.rarb < mem.rrotate_a)
		mem.rrotate_a = 0;
	else if (mem.rarb >= mem.rrotate_a)
		mem.rarb = 0;
	if (mem.rarb < mem.rr && mem.rr != -1)
		
	return (mem);
}

t_mem	rarb_cmp(t_mem mem)
{
	if (mem.swap == 1)
	{
		mem.rarb = 0;
		return (mem);
	}
	if (mem.rarb != -1)
	{
		mem = rarb_basics_algo_cmp(mem);
		
	}
	
	// if (c.do_rarb == 1 && c.do_rrarrb == 1)
		// c = rarb_rrarrb_cmp(c);
	// if (c.do_rarb == 1 && c.do_rrarb == 1)
		// c = rarb_rrarb_cmp(c);
	// if (c.do_rarb == 1 && c.do_rarrb == 1)
		// c = rarb_rarrb_cmp(c);
	return (c);
}
