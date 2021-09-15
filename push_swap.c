/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:00:35 by wiozsert          #+#    #+#             */
/*   Updated: 2021/09/15 11:58:03 by wiozsert         ###   ########.fr       */
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
			printf("%d | pos : %d\n", data->nbr, data->position);
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
			printf("nombre:\t%d  :  %d\n", i, data->nbr);
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

t_data	*sort_stack_a(t_data *stack_a, t_data *pivot)
{
	
	return (stack_a);
}

t_data	*treat_data(t_data *stack_a, int numbers)
{
	t_data	*pivot;

	if (lk_ascending_order_check(stack_a) == 1)
		free_data(&stack_a);
	else if (numbers == 2)
		sab(&stack_a, 'a');
	else
	{
		stack_a = init_position(stack_a, numbers, 0);
		pivot = NULL;
		pivot = get_pivot(stack_a, pivot, numbers -1);
		stack_a = sort_stack_a(stack_a, pivot);
	}
	return (stack_a);
}

void	get_data(int ac, char **av, int count)
{
	t_data	*stack_a;
	t_data	*new;
	t_data	*tmp;

	stack_a = (t_data*)malloc(sizeof(t_data));
	stack_a->next = NULL;
	stack_a->nbr = ft_atoi(av[count]);
	if (stack_a == NULL)
		exit (EXIT_FAILURE);
	while (++count < ac)
	{
		tmp = stack_a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new = (t_data*)malloc(sizeof(t_data));
		if (new == NULL)
			exit (EXIT_FAILURE);
		new->nbr = ft_atoi(av[count]);
		new->next = NULL;
		tmp->next = new;
	}
	if (lk_ascending_order_check(stack_a) != 1)
		stack_a = treat_data(stack_a, ac -1);
	free_data(&stack_a);
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

Attention dans le sujet il ne faut pas traiter au cas par cas
*/