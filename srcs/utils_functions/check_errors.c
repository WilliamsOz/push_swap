/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:36:00 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/29 12:59:44 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static long	latoi(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = res * sign;
	return (res);
}

static int	more_or_less_then_int(long nbr)
{
	long	max_int;
	long	min_int;

	max_int = 2147483647;
	min_int = -2147483648;
	if (nbr > max_int || nbr < min_int)
		return (-1);
	return (0);
}

static int	is_duplicate_or_not_integer(int ac, char **av, int count)
{
	int		cmp;
	long	keep;
	long	tmp;

	while (count < ac)
	{
		keep = latoi(av[count]);
		cmp = count + 1;
		while (cmp < ac)
		{
			tmp = latoi(av[cmp]);
			if (more_or_less_then_int(tmp) == -1
				|| more_or_less_then_int(tmp) == -1)
				return (-1);
			if (keep == tmp)
				return (-1);
			cmp++;
		}
		count++;
	}
	return (0);
}

static int	is_digit(int ac, char **tab)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (count < ac)
	{
		if (i == 0 && tab[count][i] == '\0')
			return (-1);
		while (tab[count][i] != '\0')
		{
			if (tab[count][i] == '-' && tab[count][i + 1] == '0')
				return (-1);
			if (ft_isdigit(tab[count][i]) == 0 && tab[count][i] != '-')
				return (-1);
			if (tab[count][i] == '-' && ft_isdigit(tab[count][i + 1]) == 0)
				return (-1);
			i++;
		}
		i = 0;
		count++;
	}
	return (0);
}

int	check_errors(int ac, char **av)
{
	long	tmp;

	tmp = latoi(av[1]);
	if (more_or_less_then_int(tmp) == -1)
		return (-1);
	if ((is_digit(ac, av) == -1)
		|| (is_duplicate_or_not_integer(ac, av, 1) == -1))
		return (-1);
	return (0);
}
