/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknow_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:26:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/25 15:13:11 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_checker	sort_move(t_checker c, char *move)
{
	 if (ft_strcmp(c.sa, move, 0) == 1)
		c.do_sa = 1;
	else if (ft_strcmp(c.sb, move, 0) == 1)
		c.do_sb = 1;
	else if (ft_strcmp(c.ss, move, 0) == 1)
		c.do_ss = 1;
	else if (ft_strcmp(c.pa, move, 0) == 1)
		c.do_pa = 1;
	else if (ft_strcmp(c.pb, move, 0) == 1)
		c.do_pb = 1;
	else if (ft_strcmp(c.ra, move, 0) == 1)
		c.do_ra = 1;
	else if (ft_strcmp(c.rb, move, 0) == 1)
		c.do_rb = 1;
	else if (ft_strcmp(c.rr, move ,0) == 1)
		c.do_rr = 1;
	else if (ft_strcmp(c.rra, move, 0) == 1)
		c.do_rra = 1;
	else if (ft_strcmp(c.rrb, move, 0) == 1)
		c.do_rrb = 1;
	else if (ft_strcmp(c.rrr, move, 0) == 1)
		c.do_rrr = 1;
	return (c);
}

t_checker	*init_do_move(t_checker *c)
{
	(*c).do_sa = 0;
	(*c).do_sb = 0;
	(*c).do_ss = 0;
	(*c).do_pa = 0;
	(*c).do_pb = 0;
	(*c).do_ra = 0;
	(*c).do_rb = 0;
	(*c).do_rr = 0;
	(*c).do_rra = 0;
	(*c).do_rrb = 0;
	(*c).do_rrr = 0;
	return (c);
}

t_checker	*init_move(t_checker *c)
{
	(*c).sa = "sa\n";
	(*c).sb = "sb\n";
	(*c).ss = "ss\n";
	(*c).pa = "pa\n";
	(*c).pb = "pb\n";
	(*c).ra = "ra\n";
	(*c).rb = "rb\n";
	(*c).rr = "rr\n";
	(*c).rra = "rra\n";
	(*c).rrb = "rrb\n";
	(*c).rrr = "rrr\n";
	return (c);
}

int	is_unknow_move(char *str, t_checker c)
{
	if (ft_strcmp(str, c.sa, 0) == 1)
		return (1);
	else if (ft_strcmp(str, c.sb, 0) == 1)
		return (1);
	else if (ft_strcmp(str, c.ss, 0) == 1)
		return (1);
	else if (ft_strcmp(str, c.pa, 0) == 1)
		return (1);
	else if (ft_strcmp(str, c.pb, 0) == 1)
		return (1);
	else if (ft_strcmp(str, c.ra, 0) == 1)
		return (1);
	else if (ft_strcmp(str, c.rb, 0) == 1)
		return (1);
	else if (ft_strcmp(str, c.rr, 0) == 1)
		return (1);
	else if (ft_strcmp(str, c.rra, 0) == 1)
		return (1);
	else if (ft_strcmp(str, c.rrb, 0) == 1)
		return (1);
	else if (ft_strcmp(str, c.rrr, 0) == 1)
		return (1);
	return (-1);
}

