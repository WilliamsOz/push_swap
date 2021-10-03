/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:00:35 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/03 11:00:55 by wiozsert         ###   ########.fr       */
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

t_data	*sort_three_digit(t_data *a)
{
	int	d_one;
	int	d_two;
	int	d_three;

	d_one = a->nbr;
	d_two = a->next->nbr;
	d_three = a->next->next->nbr;
	if (d_one > d_two && d_two > d_three)
	{
		sab(&a, 'a');
		rrab(&a, 'a');
	}
	else if (d_one < d_two && d_three < d_one)
		rrab(&a, 'a');
	else if (d_two > d_three && d_three > d_one)
	{
		rrab(&a, 'a');
		sab(&a, 'a');
	}
	else if (d_one > d_two && d_three > d_one)
		sab(&a, 'a');
	else if (d_one > d_three && d_three > d_two)
		rab(&a, 'a');
	return (a);
}

t_data	*find_pos(t_data *a, int numbers, int position, int count)
{
	t_data	*tmp;

	tmp = a;
	while (tmp->pos != position)
	{
		tmp = tmp->next;
		count++;
	}
	if (count > numbers / 2)
		while(a->pos != position)
			rrab(&a, 'a');
	else
		while (a->pos != position)
			rab(&a, 'a');
	return (a);
}

t_data	*sort_five_digit(t_data *a, t_data *b, int numbers)
{
	a = init_position(a, numbers, 0);
	a = find_pos(a, numbers, 0, 0);
	pb(&a, &b);
	a = find_pos(a, numbers, 1, 0);
	pb(&a, &b);
	a = sort_three_digit(a);
	pa(&a, &b);
	pa(&a, &b);
	return (a);
}

t_data	*treat_data(t_data *a, int numbers)
{
	t_data	*b;
	// t_data	*pivot;

	b = NULL;
	if (lk_ascending_order_check(a) == 1)
		free_data(&a);
	else if (numbers == 2)
		sab(&a, 'a');
	else if (numbers == 3)
		a = sort_three_digit(a);
	else if (numbers == 5)
		a = sort_five_digit(a, b, numbers);
	// else
	// {
	// 	a = init_position(a, numbers, 0);
	// 	pivot = NULL;
	// 	pivot = get_pivot(a, pivot, numbers -1);
	// 	a = divide_stack(a, pivot);
	// }
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
	if (lk_ascending_order_check(a) != 1)
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
OK Verifier l'algo du check_errors
EC Separer en plusieurs algo en fonction du nb d'arg

Faire l'algo pour 3 entiers entre 2 et 3 operation

Faire l'algo pour 5 entiers max 12

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

//? Attention dans le sujet il ne faut pas traiter au cas par cas
*/