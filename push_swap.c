/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:00:35 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/05 11:37:09 by wiozsert         ###   ########.fr       */
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

void	divide_stack(t_data **a, t_data **b, t_data *pv, int count)
{
	t_data	*tmp_a;
	t_data	*tmp_b;
	int		ind;

	ind = 0;
	tmp_a = (*a);
	tmp_b = (*b);
	if (count % 2 == 0)
		ind = 1;
	count /= 2;
	while (count > 0)
	{
		if ((tmp_a->nbr < pv->nbr) || (tmp_a->nbr == pv->nbr && ind == 1))
		{
			pb(&tmp_a, &tmp_b);
			count--;
		}
		else
			rab(&tmp_a, 'a');
	}
	(*a) = tmp_a;
	(*b) = tmp_b;
}

t_data	*get_med(t_data *stack, int len)
{
	t_data	*med;

	med = stack;
	len--;
	while (med->pos != len)
		med = med->next;
	PRINTD(med->pos)
	PRINTD(med->nbr)
	return (med);
}

void	find_digit_to_move(t_data **a, t_data **b, t_data *med_a, t_data *med_b)
{
	t_data	*tmp_a;
	t_data	*tmp_b;
	
	tmp_a = (*a);
	tmp_b = (*b);
	if (is_sorted(tmp_a) == 0 && is_sorted(tmp_b) == 0)
		while ((tmp_a->pos < med_a->pos && tmp_b->pos > med_b->pos) ||
			(tmp_a->ind == -1 && tmp_b->ind == 0))
			rr(&tmp_a, &tmp_b);
	if (is_sorted(tmp_a) == 0)
		while (tmp_a->pos < med_a->pos || tmp_b->ind == -1)
			rab(&tmp_a,'a');
	if (is_sorted(tmp_b) == 0)
		while (tmp_b->pos > med_a->pos || tmp_b->ind == -1)
			rab(&tmp_b,'b');
	(*a) = tmp_a;
	(*b) = tmp_b;
}

void	move_digit(t_data **a, t_data **b, t_data *med_a, t_data *med_b)
{
	t_data	*tmp_a;
	t_data	*tmp_b;
	
	tmp_a = (*a);
	tmp_b = (*b);
	while (tmp_a->next != med_a && tmp_b->next != med_b)
	{
		show_nums(tmp_a, 'a');
		show_nums(tmp_b, 'b');
		ss(&tmp_a, &tmp_b);
		rr(&tmp_a, &tmp_b);
	}
	while (tmp_a->next != med_a) 
	{
		sab(&tmp_a, 'a');
		rab(&tmp_a, 'a');
	}
	while (tmp_b->next != med_b)
	{
		show_nums(tmp_b, 'b');
		// show_nums(tmp_a, 'a');
		sab(&tmp_b, 'b');
		rab(&tmp_b, 'b');
	}
	tmp_a->ind = -1;
	tmp_b->ind = -1;
	// ss(&tmp_a, &tmp_b);
	while (tmp_a == med_a || tmp_a->ind == -1)
		rr(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

int		med_b_is_sorted(t_data *b, t_data *med)
{
	t_data	*tmp;
	int		min_pos;

	tmp = b;
	min_pos = 1;
	while (tmp->pos > tmp->next->pos)
	{
		tmp = tmp->next;
		min_pos++;
	}
	if (min_pos == med->pos)
		return (1);
	return (0);
}

int		med_a_is_sorted(t_data *a, t_data *med)
{
	t_data	*tmp;
	int		max_pos;

	tmp = a;
	max_pos = get_max_pos(a) - med->pos;
	while (tmp->pos < tmp->next->pos)
	{
		tmp = tmp->next;
		max_pos--;
	}
	if (max_pos == 0)
		return (1);
	return (0);
}

t_data	*sort_stacks(t_data *a, t_data *b, t_data *med_a, t_data *med_b)
{
	if (is_sorted(a) == 1 && is_sorted(b) == 1)
		return (a);
	else
	{
		find_digit_to_move(&a, &b, med_a, med_b);
		move_digit(&a, &b, med_a, med_b);
		if (med_a_is_sorted(a, med_a) == 1 && med_b_is_sorted(b, med_b) == 1)
		{
			SA
			SB
			PRINTD(counter)
			return (a);
		}
		else
			sort_stacks(a, b, med_a, med_b);
	}
	return (a);
}

t_data	*prepare_stacks(t_data *a, t_data *b, t_data *pv, int digits)
{
	t_data	*med_a;
	t_data	*med_b;
	int		len_stack;

	med_a = a;
	med_b = b;
	divide_stack(&a, &b, pv, digits);
	len_stack = ft_lstsize(a);
	a = init_position(a, len_stack, 0);
	if (len_stack % 2 == 1)
		len_stack++;
	med_a = get_med(a, len_stack / 2);
	len_stack = ft_lstsize(b);
	b = init_position(b, len_stack, 0);
	if (len_stack % 2 == 1)
		len_stack++;
	med_b = get_med(b , len_stack / 2);
	a = sort_stacks(a, b, med_a, med_b);
	a = init_ind(a);
	b = init_ind(b);
	return (a);
}

t_data	*treat_data(t_data *a, int digits)
{
	t_data	*b;
	t_data	*pivot;

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
	else
	{
		a = init_position(a, digits, 0);
		pivot = NULL;
		pivot = get_pivot(a, pivot, digits -1);
		a = prepare_stacks(a, b, pivot, digits);
	}
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

// commencer a trier avec les premiere mediane
// faire un algo qui va trouver les prochaine mediane
// continuer a trier, puis ainsi de suite

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
