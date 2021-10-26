/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:11:57 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/26 18:01:46 by wiozsert         ###   ########.fr       */
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

static int	is_there_duplicate(int ac, char **av, int tmp, int count)
{
	int	count2;
	int	tmp2;

	while (count < ac - 1)
	{
		tmp = ft_atoi(av[count]);
		count2 = count + 1;
		while (count2 < ac)
		{
			tmp2 = ft_atoi(av[count2]);
			if (tmp == tmp2)
				return (-1);
			else
				count2++;
		}
		count++;
	}
	return (0);
}

static int	is_less_or_more_than_int(int ac, char **av, long nbr, int count)
{
	long	max_int;
	long	min_int;

	max_int = 2147483647;
	min_int = -2147483648;
	while (count < ac)
	{
		nbr = latoi(av[count]);
		if (nbr > max_int || nbr < min_int)
			return (-1);
		else
			count++;
	}
	return (0);
}

static int	is_not_integer(int ac, char **av, int count)
{
	int		i;

	i = 0;
	while (count < ac)
	{
		while (av[count][i] != '\0')
		{
			if (av[count][i] == '-' && av[count][i + 1] == '0')
				return (-1);
			if (ft_isdigit(av[count][i]) == 0 && av[count][i] != '-')
				return (-1);
			if (av[count][i] == '-' && ft_isdigit(av[count][i + 1]) == 0)
				return (-1);
			i++;
		}
		i = 0;
		count++;
	}
	return (0);
}

int	check_bonus_errors(int ac, char **av, int count)
{
	int		i;

	i = 0;
	while (count < ac)
	{
		if (av[count][i] == '\0')
			return (-1);
		else
			count++;
	}
	if (is_not_integer(ac, av, 1) == -1
		|| is_less_or_more_than_int(ac, av, 0, 1) == -1
		|| is_there_duplicate(ac, av, 0, 1) == -1)
		return (-1);
	return (0);
}
