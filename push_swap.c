/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:00:35 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/29 13:00:50 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*treat_data(t_data *a, int digits)
{
	t_data	*b;

	b = NULL;
	if (is_sorted(a) == 1)
		free_data(&a);
	else if (digits == 2)
		sab(&a, 'a', 1);
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

	a = (t_data *)malloc(sizeof(t_data));
	if (a == NULL)
		exit (EXIT_FAILURE);
	a->next = NULL;
	a->nbr = ft_atoi(av[count]);
	while (++count < ac)
	{
		tmp = a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new = (t_data *)malloc(sizeof(t_data));
		if (new == NULL)
			exit (EXIT_FAILURE);
		new->nbr = ft_atoi(av[count]);
		new->next = NULL;
		tmp->next = new;
	}
	if (is_sorted(a) != 1)
		a = treat_data(a, ac - 1);
	free_data(&a);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	if (check_errors(ac, av) == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ac == 2)
		return (0);
	else
		get_data(ac, av, 1);
	return (0);
}
