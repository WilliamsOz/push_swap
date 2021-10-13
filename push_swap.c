/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:00:35 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/13 13:28:43 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_data(t_data **data)
{
	t_data	*tmp;

	if (*data != NULL)
	{
		while ((*data) != NULL)
		{
			tmp = *data;
			*data = (*data)->next;
			free(tmp);
		}
	}
}

void	show_nums(t_data *data, char c)
{
	int		i;

	i = 1;
	if (data == NULL)
	{
		KYEL
		printf("[----------La pile %c est vide----------]", c);
		KSTOP
		printf("\n\n");
	}
	else
	{
		if (c == 'A')
		{
		KGRN
		printf("------------PILE %c-------------\n", c);
		while (data != NULL)
		{
			KYEL
			printf("pos : %d", data->pos);
			KSTOP
			KGRN
			printf("| nbr = %d\n", data->nbr);
			data = data->next;
			i++;
		}
		printf("-------------------------------");
		KSTOP
		printf("\n\n");
		}
		else
		{
		KCYN
		printf("------------PILE %c-------------\n", c);
		while (data != NULL)
		{
			KYEL
			printf("pos : %d", data->pos);
			KSTOP
			KGRN
			printf("| nbr = %d\n", data->nbr);
			data = data->next;
			i++;
		}
		printf("-------------------------------");
		KSTOP
		printf("\n\n");
		}
	}
}

//

void	do_drrotate(t_data **a, t_data **b, t_check c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	c.d_rrr = 0;
	show_nums(*a, 'a');
	show_nums(*b, 'b');
	while (c.d_rra > 0 && c.d_rrb > 0)
	{
		c.d_rrr++;
		c.d_rra--;
		c.d_rrb--;
	}
	while (c.d_rrr-- > 0)
		rrr(&tmp_a, &tmp_b);
	while (c.d_rra-- > 0)
		rrab(&tmp_a, 'a');
	while (c.d_rrb-- > 0)
		rrab(&tmp_b, 'b');
	pa(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
	show_nums(*a, 'a');
	show_nums(*b, 'b');
	exit (EXIT_FAILURE);
}

t_check		get_d_rr(t_check c)
{
	int	tmp_da;
	int	tmp_db;

	tmp_da = c.d_rra;
	tmp_db = c.d_rrb;
	while (tmp_da > 0 && tmp_db > 0)
	{
		c.d_rrr++;
		tmp_da--;
		tmp_db--;
	}
	c.d_rrr = c.d_rrr + tmp_da + tmp_db;
	return (c);
}

t_data		*get_pos_b(t_data *b, t_data *tmp_b, t_check *c)
{
	t_data	*tmp;

	if ((*c).d_rrb == 0)
	{
		(*c).d_rrb += 1;
		tmp = get_end(b);
	}
	else
	{
		(*c).d_rrb += 1;
		tmp = b;
		while (tmp->next != tmp_b)
			tmp = tmp->next;
	}
	return (tmp);
}

t_check		d_rrotate_check(t_data *a, t_data *b, t_check c, int count)
{
	t_data	*end;
	t_data	*tmp_a;
	t_data	*tmp_b;
	int		save;

	tmp_a = a;
	save = count;
	tmp_b = NULL;
	tmp_b = get_pos_b(b, tmp_b, &c);
	end = get_end(a);
	c.d_rra = 0;
	while (save > 0 && tmp_a != NULL && b != NULL)
	{
		while (b->pos < end->pos || b->pos > tmp_a->pos)
		{
			c.d_rra++;
			tmp_a = a;
			while (tmp_a->next != end)
				tmp_a = tmp_a->next;
			end = tmp_a;
			tmp_a = end->next;
		}
		if (count == 0 && save > 0)
			c = d_rrotate_check(a, b, c, save - 1);
		if (count > 0)
		{
			c.d_rrotate = 1;
			return (c);
		}
	}
	return (c);
}

t_check		multiples_check(t_data *a, t_data *b, t_check c, int count)
{
	c = rotate_check(a, b, c);
	c = rrotate_check(a, b,c);
	c = swap_check(a, b, c);
	count = c.rotate_a;
	if (c.rrotate_a < count)
		count = c.rrotate_a;
	if (c.swap_a == -1 && count > 2)
	{
		c = d_rotate_check(a, b, c, count - 1);
	}
	if (c.swap_a == -1 && count > 2)
	{
		c = d_rrotate_check(a, b, c, count - 1);
	}
	return (c);
}

void		choose_best_move(t_data **a, t_data **b, t_check c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	if (c.d_rotate == 1)
		c = get_d_r(c);
	if (c.d_rrotate == 1)
		c = get_d_rr(c);
	if (c.d_rotate == 1 && c.d_r < c.rotate_a && c.d_r < c.rrotate_a
		&& c.d_r <= c.d_rrr)
		do_drotate(&tmp_a, &tmp_b, c);
	else if (c.d_rrotate == 1 && c.d_rrr < c.rotate_a && c.d_rrr < c.rrotate_a 
		&& c.d_rrr < c.d_r)
		do_drrotate(&tmp_a, &tmp_b, c);
	else if (c.swap_a == 2)
		do_swap(&tmp_a, &tmp_b);
	else if (c.rotate_a <= c.rrotate_a)
		do_rotate(&tmp_a, &tmp_b, c);
	else if (c.rrotate_a < c.rotate_a)
		do_rrotate(&tmp_a, &tmp_b, c);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

void		sort_stacks(t_data **a, t_data **b, t_data *tmp_a, t_data *tmp_b)
{
	t_data	*end;
	t_check	c;
	
	while (ft_lstsize(*b) > 0)
	{
		end = get_end(*a);
		if (tmp_b->pos < tmp_a->pos && tmp_b->pos > end->pos)
			pa(&tmp_a, &tmp_b);
		else
		{
			init_check(&c);
			c = multiples_check(tmp_a, tmp_b, c, 0);
			choose_best_move(&tmp_a, &tmp_b, c);
		}
		(*a) = tmp_a;
		(*b) = tmp_b;
	}
	// show_nums((*a), 'a');
	// show_nums((*b), 'b');
	(*a) = finish_sorting(tmp_a, ft_lstsize(*a), 1);
}

t_data	*prepare_stacks(t_data *a, t_data *b, int digits)
{
	t_keep	keep;
	t_data	*tmp_a;
	t_data	*tmp_b;

	a = init_position(a, digits, 1);
	keep.first = 1;
	keep.mid = ft_lstsize(a) / 2;
	keep.end = ft_lstsize(a);
	divide_stack(&a, &b, keep, digits);
	if (is_sorted(a) == 0)
		a = sort_three_digit(a, 0, 0, 0);
	// SB
	tmp_a = a;
	tmp_b = b;
	sort_stacks(&a, &b, tmp_a, tmp_b);
	// SA
	// SB
	PRINTD(counter)
	if (is_sorted(a) == 0)
	{
		KRED
		printf("\nLISTE NON TRIEE\n");
		KSTOP
	}
	else
	{
		KGRN
		printf("\nLISTE TRIEE\n");
		KSTOP
	}
	return (a);
}

t_data	*treat_data(t_data *a, int digits)
{
	t_data	*b;

	b = NULL;
	if (is_sorted(a) == 1)
		free_data(&a);
	else if (digits == 2)
		sab(&a, 'a');
	else if (digits == 3)
		a = sort_three_digit(a, 0, 0, 0);
	else if (digits == 4)
		a = sort_four_digit(a, b, digits, 0);
	else if (digits == 5)
		a = sort_five_digit(a, b, digits);
	else if (digits < 250)
		a = prepare_stacks(a, b, digits);
	// else if (digits > 250)
		// a = prepare_stacks(a, b, digits);
	return (a);
}

void	get_data(int ac, char **av, int count)
{
	t_data	*a;
	t_data	*new;
	t_data	*tmp;

	a = (t_data*)malloc(sizeof(t_data));
	a->next = NULL;
	a->nbr = ft_atoi(av[count]);
	if (a == NULL)
		exit (EXIT_FAILURE);
	while (++count < ac)
	{
		tmp = a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new = (t_data*)malloc(sizeof(t_data));
		if (new == NULL)
			exit (EXIT_FAILURE);
		new->nbr = ft_atoi(av[count]);
		new->next = NULL;
		tmp->next = new;
	}
	if (is_sorted(a) != 1)
		a = treat_data(a, ac -1);
	free_data(&a);
}

int		main(int ac, char **av)
{
	counter = 0;
	xd = 0;
	if (ac < 3)
		return (0);
	else if (check_errors(ac, av) == -1)
		write(1, "Error\n", 6);
	else
		get_data(ac, av, 1);
	return (0);
}

/*

Faire l'algo pour 100 entiers bareme 1 a 5 ;
-700 : 5
-900 : 4
-1100 : 3
-1300 : 2
-1500 ; 1

Faire l'algo pour 500 entiers bareme 1 a 5 ;
-5500 : 5
-7000 : 4
-8500 : 3
-10 000 : 2
-11 500 : 1
*/
