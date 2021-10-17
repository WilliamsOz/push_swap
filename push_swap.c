/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:00:35 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/17 17:29:53 by wiozsert         ###   ########.fr       */
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

t_check		sort_best_move(t_check c)
{
	if (c.do_rarb == 1)
		c = get_rarb(c);
	if (c.do_rrarb == 1)
		c.rrarb = c.rb + c.rra;
	if (c.do_rrarrb == 1)
		c = get_rrarrb(c);
	if (c.do_rarrb == 1)
		c = get_rarrb(c);
	PRINTD(c.rotate_a)
	PRINTD(c.rrotate_a)
	PRINTD(c.rarb)
	PRINTD(c.rrarb)
	PRINTD(c.rrarrb)
	PRINTD(c.rarrb)
	c = rarb_cmp(c);
	c = rrarrb_cmp(c);
	c = rrarb_cmp(c);
	c = rarrb_cmp(c);
	return (c);
}

void		choose_best_move(t_data **a, t_data **b, t_check c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	c = sort_best_move(c);
	if (c.swap_a == 2)
		do_swap(&tmp_a, &tmp_b);
	else if (c.do_rarb == 1)
		do_rarb(&tmp_a, &tmp_b, c);
	else if (c.do_rrarb == 1)
		do_rrarb(&tmp_a, &tmp_b, c);
	else if (c.do_rrarrb == 1)
		do_rrarrb(&tmp_a, &tmp_b, c);
	else if (c.do_rarrb == 1)
		do_rarrb(&tmp_a, &tmp_b, c);
	else if (c.rotate_a <= c.rrotate_a)
		do_rotate(&tmp_a, &tmp_b, c);
	else if (c.rrotate_a < c.rotate_a)
		do_rrotate(&tmp_a, &tmp_b, c);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_check		multiples_check(t_data *a, t_data *b, t_check c, int count)
{
	c = rotate_check(a, b, c);
	if (c.rotate_a == 27)
		exit (EXIT_FAILURE);
	c = rrotate_check(a, b, c);
	c = swap_check(a, b, c);
	count = c.rotate_a;
	if (c.rrotate_a < count)
		count = c.rrotate_a;
	c.count = count;
	if (c.swap_a == -1 && count > 0)
		c = rarb_check(a, b->next, c, count - 1);
	c.count = count;
	if (c.swap_a == -1 && count > 0)
		c = rrarrb_check(a, b, c, count - 1);
	c.count = count;
	if (c.swap_a == -1 && count > 0)
		c = rrarb_check(a, b->next, c, count - 1);
	c.count = count;
	if (c.swap_a == -1 && count > 0)
		c = rarrb_check(a, b->next, c, count - 1);
	return (c);
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
	(*a) = finish_sorting(tmp_a, ft_lstsize(*a), 1);
}

#include <libc.h>

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
	tmp_a = a;
	tmp_b = b;
	sort_stacks(&a, &b, tmp_a, tmp_b);
	// SA
	// SB
	PRINTD(counter)
	if (is_sorted(a) == 0)
	{
		KRED
		printf("\nLISTE NON TRIEE : |%d|\n", ft_lstsize(a));
		KSTOP
	}
	else
	{
		KGRN
		printf("\nLISTE TRIEE : |%d|\n", ft_lstsize(a));
		KSTOP
	}
	return (a);
}

int	check_pos(int nbr, int digits)
{
	if (nbr == 1 || nbr == digits || nbr == (digits / 2) ||
		nbr == ((digits / 2) / 2) || nbr == ((digits / 2) * 1.5))
		return (1);
	return (0);
}

t_data	*prepare_big_stacks(t_data *a, t_data *b, int digits)
{
	t_data	*tmp;
	int		count;

	count = digits - 5;
	tmp = a;
	a = init_position(a, digits, 1);
	while (count > 0)
	{
		tmp = a;
		if (check_pos(tmp->pos, digits) == 1)
		{
			rrab(&a, 'a');
			tmp = tmp->next;
		}
		else
		{
			pb(&a, &b);
			count--;
		}
	}
	SA
	SB	
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
	else if (digits > 250)
		a = prepare_big_stacks(a, b, digits);
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
