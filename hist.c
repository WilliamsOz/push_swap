/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:00:35 by wiozsert          #+#    #+#             */
/*   Updated: 2021/08/30 16:37:21 by wiozsert         ###   ########.fr       */
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
			printf("nombre:\t%d  :  %d\n", i, data->nbr);
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

void	divide_tab(t_data **a, t_data **b)
{
	t_data		*pivot;
	t_data		*tmp;
	
	pivot = (*a);
	tmp = (*a)->next;
	rab(a, 'a');
	while (tmp != pivot)
	{
		if (tmp->nbr < pivot->nbr)
		{
			tmp = tmp->next;
			pb(a,b);
		}
		else
		{
			tmp = tmp->next;
			rab(a, 'a');
		}
	}
}

// void	push_upper(t_data **a, t_data **b, int count, int len)
// {
// 	int	move;

// 	if (count == -1)
// 	{
// 		rrab(b, 'b');
// 		pa(a, b);
// 	}
// 	else
// 	{
// 		if (count > len / 2)
// 		{
// 			move = len - count;
// 			while (--move > 0)
// 			{
// 				rrab(b, 'b');
// 			}
// 			pa(a, b);
// 		}
// 		else
// 		{
// 			count
// 		}
// 	}
// }

t_data	*get_upper(t_data *b)
{
	t_data	*ptr;
	t_data	*upper;

	ptr = b;
	upper = b;
	while (ptr != NULL)
	{
		if (ptr->nbr > upper->nbr)
			upper = ptr;
		ptr = ptr->next;
	}
	return (upper);
}

int		where_is_upper(t_data *upper, t_data *b, int position)
{
	t_data	*tmp;
	int		len;

	tmp = b;
	len = ft_lstsize(b) - 1;
	while (tmp != upper)
	{
		position++;
		tmp = tmp->next;
	}
	if (len == position && len != 0)
		return (-1);
	return (position);
}

t_data	**sort_lower(t_data **a, t_data **b)
{
	int		position;
	t_data	*upper;
	
	while ((*b) != NULL)
	{
		upper = get_upper((*b));
		position = where_is_upper(upper, (*b), 0);
		if (position == -1 && (*b)->next != NULL)
			rrab(b, 'b');
		else if (position > (ft_lstsize((*b)) - 1) / 2)
		{
			position = (ft_lstsize((*b))) - position;
			while (position-- > 0)
				rrab(b, 'b');
		}
		else
		{
			while (position-- > 0)
				rab(b, 'b');
		}
		pa(a, b);
	}
	return (a);
}

t_data	*get_lower(t_data *b)
{
	t_data	*ptr;
	t_data	*lower;

	ptr = b;
	lower = b;
	while (ptr != NULL)
	{
		if (ptr->nbr < lower->nbr)
			lower = ptr;
		ptr = ptr->next;
	}
	return (lower);
}

int		where_is_lower(t_data *lower, t_data *b, int position)
{
	t_data	*tmp;
	int		len;

	tmp = b;
	len = ft_lstsize(b) - 1;
	while (tmp != lower)
	{
		position++;
		tmp = tmp->next;
	}
	if (len == position && len != 0)
		return (-1);
	return (position);
}

t_data	**sort_upper(t_data **a, t_data **b, t_data *pivot)
{
	t_data	*lower;
	int		position;

	while (pivot->next != NULL)
	{
		rrab(a, 'a');
		pb(a, b);
	}
	lower = get_lower((*b));
	position = where_is_lower(lower, (*b), 0);
	while ((*b) != NULL)
	{
		lower = get_lower((*b));
		position = where_is_lower(lower, (*b), 0);
		if (position == -1 && (*b)->next != NULL)
			rrab(b, 'b');
		else if (position > (ft_lstsize((*b)) - 1) / 2)
		{
			position = (ft_lstsize((*b))) - position;
			while (position-- > 0)
				rrab(b, 'b');
		}
		else
		{
			while (position-- > 0)
				rab(b, 'b');
		}
		pa(a, b);
		rab(a, 'a');
	}
	return (a);
}

t_data	*exploit_data(t_data *stack_a)
{
	t_data	*stack_b;
	t_data	*pivot;

	pivot = stack_a;
	stack_b = NULL;
	divide_tab(&stack_a, &stack_b);
	if (stack_b != NULL)
		sort_lower(&stack_a, &stack_b);
	sort_upper(&stack_a, &stack_b, pivot);
	free_data(&stack_b);
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
	if (lk_ascending_order_check(stack_a) == 1)
		free_data(&stack_a);
	else
	{
		stack_a = exploit_data(stack_a);
		free_data(&stack_a);
	}
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
Faire l'algo pour 3 entiers
Faire l'algo pour 5 entiers
Ameliorer l'algo pour 100 entiers
Trouver comment faire pour 500 entiers
*/