/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:00:35 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/11 20:09:45 by wiozsert         ###   ########.fr       */
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

void	divide_stack(t_data **a, t_data **b, t_keep keep)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	while (ft_lstsize(tmp_a) != 3)
	{
		if (tmp_a->pos != keep.first && tmp_a->pos != keep.mid &&
			tmp_a->pos != keep.end)
			pb(&tmp_a, &tmp_b);
		else
			rrab(&tmp_a, 'a');
	}
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_data		*get_end(t_data *a)
{
	t_data	*tmp;

	tmp = a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void		init_check(t_check *check)
{
	(*check).rotate_a = 0;
	(*check).rrotate_a = 0;
	(*check).rotate_b = 0;
	(*check).rr = 0;
}

t_check		rotate_check(t_data *a, t_data *b, t_check c)
{
	t_data	*tmp;

	tmp = a;
	while (tmp != NULL && b->pos < tmp->pos)
	{
		c.rotate_a += 1;
		tmp = tmp->next;
	}
	while (tmp != NULL && b->pos > tmp->pos)
	{
		c.rotate_a += 1;
		tmp = tmp->next;
	}
	return (c);
}

void		do_rotate(t_data **a, t_data **b, t_check c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	while (c.rotate_a > 0)
	{
		rab(&tmp_a, 'a');
		c.rotate_a--;
	}
	pa(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_check		rrotate_check(t_data *a, t_data *b, t_check c)
{
	// faire le check en reverse rotate
	t_data	*end;
	t_data	*keep;
	t_data	*tmp;

	tmp = a;
	end = get_end(a);
	while (b->pos < tmp->pos && b->pos < end->pos)
	{
		keep = end;
		end = a;
		while (end->next != keep)
			end = end->next;
		tmp = end;
		c.rrotate_a += 1;
	}
	PRINTD(c.rrotate_a)
	SA
	SB
	(void)c;
	return (c);	
}

t_check		multiples_check(t_data *a, t_data *b, t_check c)
{
	c = rotate_check(a, b, c);
	c = rrotate_check(a, b,c);
	return (c);
}

void		choose_best_move(t_data **a, t_data **b, t_check c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;
	
	tmp_a = (*a);
	tmp_b = (*b);
	(void)c;
	// do_rotate(&tmp_a, &tmp_b, c);
	// do_rrotate(&tmp_a, &tmp_b, c);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

void		sort_stacks(t_data **a, t_data **b, t_data *tmp_a, t_data *tmp_b)
{
	t_data	*end;
	t_check	c;
	
	// show_nums(tmp_a, 'a');
	// show_nums(tmp_b, 'b');
	while (ft_lstsize(*b) > 0)
	{
		end = get_end(tmp_a);
		if (tmp_b->pos > end->pos && tmp_b->pos < tmp_a->pos)
			pa(&tmp_a, &tmp_b);
		else
		{
			init_check(&c);
			c = multiples_check(tmp_a, tmp_b, c);
			// choose_best_move(&tmp_a, &tmp_b, c);
		}
		(*a) = tmp_a;
		(*b) = tmp_b;
	}
	show_nums(*a, 'a');
	show_nums(*b, 'b');
	PRINTD(counter)
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
	divide_stack(&a, &b, keep);
	tmp_a = a;
	tmp_b = b;
	sort_stacks(&a, &b, tmp_a, tmp_b);
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
