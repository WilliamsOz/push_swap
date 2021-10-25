/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:53:37 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/25 23:17:10 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	init_checker(int ac, char **av, int count)
{
	t_data	*a;
	t_data	*new;
	t_data	*tmp;
	t_data	*b;

	b = NULL;
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
	get_move(a, b);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	if (check_bonus_errors(ac, av) == -1)
	{
		write(2, "KO\n", 3);
		return (0);
	}
	if (ac == 2)
		return (0);
	else
		init_checker(ac, av, 1);
	return (0);
}
