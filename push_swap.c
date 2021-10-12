/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:00:35 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/12 20:18:01 by wiozsert         ###   ########.fr       */
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

t_check		get_d_rr(t_check c)
{
	int tmp_da;
	int	tmp_db;

	tmp_da = c.d_a;
	tmp_db = c.d_b;
	while (tmp_da > 0 && tmp_db > 0)
	{
		c.d_rr++;
		tmp_da--;
		tmp_db--;
	}
	c.d_rr = c.d_rr + tmp_da + tmp_db;
	return (c);
}

void		do_drotate(t_data **a, t_data **b, t_check c)
{
	xd++;
	t_data	*tmp_a;
	t_data	*tmp_b;
	
	tmp_a = (*a);
	tmp_b = (*b);
	c.d_rr = 0;
	show_nums((*a), 'a');
	show_nums((*b), 'b');
	while (c.d_a > 0 && c.d_b > 0)
	{
		c.d_rr++;
		c.d_a--;
		c.d_b--;
	}
	while (c.d_rr > 0)
	{
		rr(&tmp_a, &tmp_b);
		c.d_rr--;
	}
	while (c.d_a > 0)
	{
		rab(&tmp_a, 'a');
		c.d_a--;
	}
	while (c.d_b > 0)
	{
		rab(&tmp_b, 'b');
		c.d_b--;
	}
	pa(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
	if (xd == 40)
		exit (EXIT_FAILURE);
}

/* ameliorer la fonction pour aller checker toute les autres
possibilite de placer le nombre le plus vite dans la pile b
*/
t_check		double_rotate_check(t_data *a, t_data *b, t_check c, int count)
{
	t_data	*end;
	int	save;

	end = get_end(a);
	b = b->next;
	save = count;
	c.d_b++;
	while (save > 0 && a != NULL && b != NULL)
	{
		while (count > 0 && (b->pos < end->pos || b->pos > a->pos))
		{
			c.d_a++;
			end = a;
			a = a->next;
		}
		if (count == 0 && save > 0)
		{
			c.d_a = 0;
			c = double_rotate_check(a, b, c, save -1);
		}
		if (count > 0)
		{
			c.d_rotate = 1;
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
		c = double_rotate_check(a, b, c, count - 1);
	// c = next_nbr_check(a, b, c);
	return (c);
}

void		choose_best_move(t_data **a, t_data **b, t_check c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	if (c.d_rotate == 1)
		c = get_d_rr(c);
	if (c.d_rotate == 1 && c.d_rr < c.rotate_a && c.d_rr < c.rrotate_a)
	{
		// PRINTD(c.d_a)
		// PRINTD(c.d_b)
		// PRINTD(c.d_rr)
		// PRINTD(c.rotate_a)
		// PRINTD(c.rrotate_a)
		do_drotate(&tmp_a, &tmp_b, c);
	}
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
	show_nums((*a), 'a');
	show_nums((*b), 'b');
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
	tmp_a = a;
	tmp_b = b;
	sort_stacks(&a, &b, tmp_a, tmp_b);
	SA
	SB
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
