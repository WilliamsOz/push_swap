/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrarb_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:00:46 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/17 16:28:16 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

static t_check	rrarb_swap_cmp(t_check c)
{
	if (c.rrarb < c.swap_a)
		c.swap_a = -1;
	else if (c.swap_a <= c.rrarb)
		c.do_rrarb = 0;
	return (c);
}

static t_check	rrarb_rarb_cmp(t_check c)
{
	if (c.rrarb < c.rarb)
		c.do_rarb = 0;
	else if (c.rarb < c.rrarb)
		c.do_rrarb = 0;
	return (c);
}

static t_check	rrarb_rrarrb_cmp(t_check c)
{
	if (c.rrarb < c.rrarrb)
		c.do_rrarrb = 0;
	else if (c.rrarrb < c.rrarb)
		c.do_rrarb = 0;
	return (c);
}

static t_check	rrarb_rarrb_cmp(t_check c)
{
	if (c.rrarb < c.rarrb)
		c.do_rarrb = 0;
	else if (c.rarrb < c.rrarb)
		c.do_rrarb = 0;
	return (c);
}

t_check	rrarb_cmp(t_check c)
{
	if (c.do_rrarb == 1 && c.swap_a == 2)
		c = rrarb_swap_cmp(c);
	if (c.do_rrarb == 1 && c.do_rarb == 1)
		c = rrarb_rarb_cmp(c);
	if (c.do_rrarb == 1 && c.do_rrarrb == 1)
		c = rrarb_rrarrb_cmp(c);
	if (c.do_rrarb == 1 && c.do_rarrb == 1)
		c = rrarb_rarrb_cmp(c);
	return (c);
}
