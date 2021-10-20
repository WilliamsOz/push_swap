/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrarrb_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:53:44 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/20 11:56:09 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// static t_check	rrarrb_basics_algo_cmp(t_check c)
// {
// 	if (c.swap_a == 2)
// 	{
// 		if (c.rrarrb < c.swap_a)
// 			c.swap_a = -1;
// 		else if (c.swap_a <= c.rrarrb)
// 			c.do_rrarrb = 0;
// 	}
// 	if (c.do_rotate_a == 1)
// 	{
// 		if (c.rrarrb < c.rotate_a)
// 			c.do_rotate_a = 0;
// 		else if (c.rrarrb >= c.rotate_a)
// 			c.do_rrarrb = 0;
// 	}
// 	if (c.do_rrotate_a == 1)
// 	{
// 		if (c.rrarrb < c.rrotate_a)
// 			c.do_rrotate_a = 0;
// 		else if (c.rrarrb >= c.rrotate_a)
// 			c.do_rrarrb = 0;
// 	}
// 	return (c);
// }

// static t_check	rrarrb_rarb_cmp(t_check c)
// {
// 	if (c.rrarrb < c.rarb)
// 		c.do_rarb = 0;
// 	else if (c.rarb < c.rrarrb)
// 		c.do_rrarrb = 0;
// 	return (c);
// }

// static t_check	rrarrb_rrarb_cmp(t_check c)
// {
// 	if (c.rrarrb < c.rrarb)
// 		c.do_rrarb = 0;
// 	else if (c.rrarb < c.rrarrb)
// 		c.do_rrarrb = 0;
// 	return (c);
// }

// static t_check	rrarrb_rarrb_cmp(t_check c)
// {
// 	if (c.rrarrb < c.rarrb)
// 		c.do_rarrb = 0;
// 	else if (c.rarrb < c.rrarrb)
// 		c.do_rrarrb = 0;
// 	return (c);
// }

// t_check	rrarrb_cmp(t_check c)
// {
// 	if (c.do_rrarrb == 1 && (c.swap_a == 2 || c.do_rotate_a == 1
// 		|| c.do_rrotate_a == 1))
// 		c = rrarrb_basics_algo_cmp(c);
// 	if (c.do_rrarrb == 1 && c.do_rarb == 1)
// 		c = rrarrb_rarb_cmp(c);
// 	if (c.do_rrarrb == 1 && c.do_rrarb == 1)
// 		c = rrarrb_rrarb_cmp(c);
// 	if (c.do_rrarrb == 1 && c.do_rarrb == 1)
// 		c = rrarrb_rarrb_cmp(c);
// 	return (c);
// }
