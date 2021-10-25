/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_motor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:24:20 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/25 23:31:42 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	do_move_next(t_data **a, t_data **b, t_chker c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	if (c.do_ra == 1)
		rab(&tmp_a, 'a', 0);
	else if (c.do_rb == 1)
		rab(&tmp_b, 'b', 0);
	else if (c.do_rr == 1)
		rr(&tmp_a, &tmp_b, 0);
	else if (c.do_rra == 1)
		rrab(&tmp_a, 'a', 0);
	else if (c.do_rrb == 1)
		rrab(&tmp_b, 'b', 0);
	else if (c.do_rrr == 1)
		rrr(&tmp_a, &tmp_b, 0);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

static void	do_move(t_data **a, t_data **b, t_chker c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	if (c.do_sa == 1)
		sab(&tmp_a, 'a', 0);
	else if (c.do_sb == 1)
		sab(&tmp_b, 'b', 0);
	else if (c.do_ss == 1)
		ss(&tmp_a, &tmp_b, 0);
	else if (c.do_pa == 1)
		pa(&tmp_a, &tmp_b, 0);
	else if (c.do_pb == 1)
		pb(&tmp_a, &tmp_b, 0);
	else
		do_move_next(&tmp_a, &tmp_b, c);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

static void	find_move(t_data **a, t_data **b, char *move)
{
	t_data		*tmp_a;
	t_data		*tmp_b;
	t_chker		c;

	tmp_a = (*a);
	tmp_b = (*b);
	init_move(&c);
	init_do_move(&c);
	c = sort_move(c, move);
	do_move(&tmp_a, &tmp_b, c);
	free(move);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

static void	is_stack_sorted_and_b_empty(t_data *a, t_data *b)
{
	if (is_sorted(a) == 1 && ft_lstsize(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_data(&a);
	free_data(&b);
}

void	get_move(t_data *a, t_data *b)
{
	t_chker		c;
	char		*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		init_move(&c);
		if ((line == NULL || is_unknow_move(line, c) == -1))
		{
			write(2, "KO\n", 3);
			free(line);
			free_data(&b);
			free_data(&a);
			exit (EXIT_FAILURE);
		}
		find_move(&a, &b, line);
	}
	is_stack_sorted_and_b_empty(a, b);
}
