/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:53:37 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/25 15:18:12 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/* Ecrire un programme nomme checker qui prend une liste d'entier en parametre

Le programme va ensuite attendre de recevoir des
instructions en entree standard, chaque instructions
doit etre suiviees par des '\n'. Une fois les instructions
terminees, le programme va les executer sur la liste d'entier
recu en parametre.

Si apres avoir effectuer les instructions, la pile A est triee
et la pile B et vide, le programme doit afficher "OK" suivie d'un
'\n' sur la SORTIE STANDARD.
Dans tout les autres ca le programme doit afficher "KO" suivie
d'un '\n' sur la SORTIE STANDARD.

Une instruction n'existe pas et/ou est mal formatee.

*/

// Faire la fonction si une instruction n'existe pas avec gnl

static void		do_move_next(t_data **a, t_data **b, t_checker c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	if (c.do_ra == 1)
		rab(&tmp_a, 'a');
	else if (c.do_rb == 1)
		rab(&tmp_b, 'b');
	else if (c.do_rr == 1)
		rr(&tmp_a, &tmp_b);
	else if (c.do_rra == 1)
		rrab(&tmp_a, 'a');
	else if (c.do_rrb == 1)
		rrab(&tmp_b, 'b');
	else if (c.do_rrr == 1)
		rrr(&tmp_a, &tmp_b);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

static void		do_move(t_data **a, t_data **b, t_checker c)
{
	t_data	*tmp_a;
	t_data	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	if (c.do_sa == 1)
		sab(&tmp_a, 'a');
	else if (c.do_sb == 1)
		sab(&tmp_b, 'b');
	else if (c.do_ss == 1)
		ss(&tmp_a, &tmp_b);
	else if (c.do_pa == 1)
		pa(&tmp_a, &tmp_b);
	else if (c.do_pb == 1)
		pb(&tmp_a, &tmp_b);
	else
		do_move_next(a, b, c);
	(*a) = tmp_a;
	(*b) = tmp_b;
}

static void		find_move(t_data *a, t_data *b, char *move)
{
	t_checker	c;

	init_do_move(&c);
	c = sort_move(c, move);
	do_move(&a, &b, c);
	free(move);
}

static t_data	*get_move(t_data *a)
{
	t_checker	c;
	t_data	*b;
	char	*line;
	int	eof;

	b = NULL;
	eof = 1;
	while (eof > 0)
	{
		eof = get_next_line(0, &line);
		init_move(&c);	
		if (is_unknow_move(line, c) == -1)
		{
			write(2, "KO\n", 3);
			free(line);
			free_data(&b);
			free_data(&a);
			return (a);
		}
		else
			find_move(a, b, line);
	}
	return (a);
}

static void	init_checker(int ac, char **av, int count)
{
	t_data  *a;
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
		new = (t_data*)malloc(sizeof(t_data));
		if (new == NULL)
			exit (EXIT_FAILURE);
		new->nbr = ft_atoi(av[count]);
		new->next = NULL;
		tmp->next = new;
	}
	a = get_move(a);
}

int main(int ac, char **av)
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