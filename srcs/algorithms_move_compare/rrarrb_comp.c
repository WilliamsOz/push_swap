/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrarrb_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:53:44 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/18 11:50:05 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_check	rrarrb_swap_cmp(t_check c)
{
	if (c.rrarrb < c.swap_a)
		c.swap_a = -1;
	else if (c.swap_a <= c.rrarrb)
		c.do_rrarrb = 0;
	return (c);
}

static t_check	rrarrb_rarb_cmp(t_check c)
{
	if (c.rrarrb < c.rarb)
		c.do_rarb = 0;
	else if (c.rarb < c.rrarrb)
		c.do_rrarrb = 0;
	return (c);
}

static t_check	rrarrb_rrarb_cmp(t_check c)
{
	if (c.rrarrb < c.rrarb)
		c.do_rrarb = 0;
	else if (c.rrarb < c.rrarrb)
		c.do_rrarrb = 0;
	return (c);
}

static t_check	rrarrb_rarrb_cmp(t_check c)
{
	if (c.rrarrb < c.rarrb)
		c.do_rarrb = 0;
	else if (c.rarrb < c.rrarrb)
		c.do_rrarrb = 0;
	return (c);
}

t_check	rrarrb_cmp(t_check c)
{
	if (c.do_rrarrb == 1 && c.swap_a == 2)
		c = rrarrb_swap_cmp(c);
	if (c.do_rrarrb == 1 && c.do_rarb == 1)
		c = rrarrb_rarb_cmp(c);
	if (c.do_rrarrb == 1 && c.do_rrarb == 1)
		c = rrarrb_rrarb_cmp(c);
	if (c.do_rrarrb == 1 && c.do_rarrb == 1)
		c = rrarrb_rarrb_cmp(c);
	return (c);
}
