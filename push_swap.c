/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:00:35 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/24 23:20:00 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gucci(t_data *a)
{
	if (is_sorted(a) == 1)
	{
		KGRN
		printf("Stack is sorted [len of stack : %d]\n", ft_lstsize(a));
		KSTOP
		if  (ft_lstsize(a) < 250)
		{
			if (counter < 700)
			{
				KGRN
				printf("|%d| 5 / 5\n", counter);
			}
			else if (counter < 900)
			{
				KMAG
				printf("|%d| 4 / 5\n", counter);
			}
			else if (counter < 1100)
			{
				KORG
				printf("|%d| 3 / 5\n", counter);
			}
			else if (counter < 1300)
			{
				KYEL
				printf("|%d| 2 / 5\n", counter);
			}
			else if (counter < 1500)
			{
				KWHT
				printf("|%d| 1 / 5\n", counter);
			}
			else
			{
				KRED
				printf("|%d| 0 / 5\n", counter);
			}
		}
		else
		{
			if (counter < 5500)
			{
				KGRN
				printf("|%d| 5 / 5\n", counter);
			}
			else if (counter < 7000)
			{
				KBLU
				printf("|%d| 4 / 5\n", counter);
			}
			else if (counter < 8500)
			{
				KORG
				printf("|%d| 3 / 5\n", counter);
			}
			else if (counter < 10000)
			{
				KYEL
				printf("|%d| 2 / 5\n", counter);
			}
			else if (counter < 11500)
			{
				KWHT
				printf("|%d| 1 / 5\n", counter);
			}
			else
			{
				KRED
				printf("|%d| 0 / 5\n", counter);
			}
		}
		KSTOP
	}
	else
	{
		KRED
		printf("Stack is not sorted [len of stack : %d]\n", ft_lstsize(a));
		KSTOP
		if  (ft_lstsize(a) < 250)
		{
			if (counter < 700)
			{
				KGRN
				printf("|%d| 5 / 5\n", counter);
			}
			else if (counter < 900)
			{
				KMAG
				printf("|%d| 4 / 5\n", counter);
			}
			else if (counter < 1100)
			{
				KORG
				printf("|%d| 3 / 5\n", counter);
			}
			else if (counter < 1300)
			{
				KYEL
				printf("|%d| 2 / 5\n", counter);
			}
			else if (counter < 1500)
			{
				KWHT
				printf("|%d| 1 / 5\n", counter);
			}
			else
			{
				KRED
				printf("|%d| 0 / 5\n", counter);
			}
		}
		else
		{
			if (counter < 5500)
			{
				KGRN
				printf("|%d| 5 / 5\n", counter);
			}
			else if (counter < 7000)
			{
				KBLU
				printf("|%d| 4 / 5\n", counter);
			}
			else if (counter < 8500)
			{
				KORG
				printf("|%d| 3 / 5\n", counter);
			}
			else if (counter < 10000)
			{
				KYEL
				printf("|%d| 2 / 5\n", counter);
			}
			else if (counter < 11500)
			{
				KWHT
				printf("|%d| 1 / 5\n", counter);
			}
			else
			{
				KRED
				printf("|%d| 0 / 5\n", counter);
			}
		}
		KSTOP
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
		a = prepare_low_stacks(a, b, digits);
	else if (digits >= 250)
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
	// DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL
	// gucci(a);
	// DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL
	free_data(&a);
}

// rajouter un check errors pour verifier le cas sur le telephone

int		main(int ac, char **av)
{
	counter = 0;
	xd = 0;
	if (ac == 1)
		return (0);
	if (check_errors(ac, av) == -1)
		write(1, "Error\n", 6);
	else if (ac < 3)
		return (0);
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
