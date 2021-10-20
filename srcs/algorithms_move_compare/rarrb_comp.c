/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rarrb_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:52:41 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/20 11:56:18 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// static t_check	rarrb_basics_algo_cmp(t_check c)
// {
// 	if (c.swap_a == 2)
// 	{
// 		if (c.rarrb < c.swap_a)
// 			c.swap_a = -1;
// 		else if (c.swap_a <= c.rarrb)
// 			c.do_rarrb = 0;
// 	}
// 	if (c.do_rotate_a == 1)
// 	{
// 		if (c.rarrb < c.rotate_a)
// 			c.do_rotate_a = 0;
// 		else if (c.rarrb >= c.rotate_a)
// 			c.do_rarrb = 0;
// 	}
// 	if (c.do_rrotate_a == 1)
// 	{
// 		if (c.rarrb < c.rrotate_a)
// 			c.do_rrotate_a = 0;
// 		else if (c.rarrb >= c.rrotate_a)
// 			c.do_rarrb = 0;
// 	}
// 	return (c);
// }

// static t_check	rarrb_rarb_cmp(t_check c)
// {
// 	if (c.rarrb < c.rarb)
// 		c.do_rarb = 0;
// 	else if (c.rarb < c.rarrb)
// 		c.do_rarrb = 0;
// 	return (c);
// }

// static t_check	rarrb_rrarrb_cmp(t_check c)
// {
// 	if (c.rarrb < c.rrarrb)
// 		c.do_rrarrb = 0;
// 	else if (c.rrarrb < c.rarrb)
// 		c.do_rarrb = 0;
// 	return (c);
// }

// static t_check	rarrb_rrarb_cmp(t_check c)
// {
// 	if (c.rarrb < c.rrarb)
// 		c.do_rrarb = 0;
// 	else if (c.rrarb < c.rarrb)
// 		c.do_rarrb = 0;
// 	return (c);
// }

// t_check	rarrb_cmp(t_check c)
// {
// 	if (c.do_rarrb == 1 && (c.swap_a == 2 || c.do_rotate_a == 1
// 		|| c.do_rrotate_a == 1))
// 		c = rarrb_basics_algo_cmp(c);
// 	if (c.do_rarrb == 1 && c.do_rarb == 1)
// 		c = rarrb_rarb_cmp(c);
// 	if (c.do_rarrb == 1 && c.do_rrarrb == 1)
// 		c = rarrb_rrarrb_cmp(c);
// 	if (c.do_rarrb == 1 && c.do_rrarb == 1)
// 		c = rarrb_rrarb_cmp(c);
// 	return (c);
// }
