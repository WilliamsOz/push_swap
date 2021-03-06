/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rarb_comp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:30:21 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/23 19:53:17 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_mem	rarb_basics_algo_cmp(t_mem mem)
{
	if (mem.rarb >= mem.rotate_a)
		mem.do_rarb = 0;
	if (mem.rarb >= mem.rrotate_a)
		mem.do_rarb = 0;
	return (mem);
}

t_mem	rarb_cmp(t_mem mem)
{
	if (mem.swap == 1)
		mem.do_rarb = 0;
	else if (mem.do_rarb == 1)
		mem = rarb_basics_algo_cmp(mem);
	return (mem);
}
