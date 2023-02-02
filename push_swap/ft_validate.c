/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:14:34 by atopalli          #+#    #+#             */
/*   Updated: 2023/01/12 22:25:44 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_args(char **av, int ac, t_struct *s)
{
	int	i;

	if (ac > 1)
	{
		i = -1;
		if (ac == 2)
			while (av[1][++i])
				if (av[1][i] == ' ')
					ac += 1;
		s->stacka = malloc(sizeof(int) * ac);
		if (s->stacka)
		{
			i = 0;
			if (av[2] == NULL)
				ft_split(av[1], s->stacka);
			else
				while (++i < ac)
					ft_split(av[i], s->stacka);
			if (ft_check_stack(ac - 1, 'd', s) == 1)
				return (1);
			free(s->stacka);
		}
	}
	return (0);
}

int	ft_check_stack(int size, char todo, t_struct *s)
{
	int	current;
	int	next;
	int	isnordered;

	isnordered = 0;
	current = -1;
	while (todo == 'd' && ++current < size)
	{
		next = current;
		while (++next < size)
			if (s->stacka[current] == s->stacka[next])
				return (0);
	}
	while (todo == 'o' && ++current < size)
	{
		next = current;
		while (++next < size)
			if (s->stacka[current] > s->stacka[next])
				isnordered = 1;
	}
	if (todo == 'o')
		return (isnordered);
	s->stacka_size = size;
	return (1);
}
