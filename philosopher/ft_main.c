/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:47:50 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/01 14:16:32 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	final;

	i = 0;
	final = 0;
	if (str[0] != '-' && str[0] != '0')
	{
		while (str[i])
		{
			final = final * 10 + (str[i] - '0');
			i += 1;
		}
		return (final);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_list	p;
	int		i;

	i = 1;
	if (ac > 4 && ac <= 6)
	{
		while (i < ac)
		{
			if (ft_atoi(av[i]) <= 0)
				return (0);
			i += 1;
		}
		p.t_must_eat = -1;
		p.n_philo = ft_atoi(av[1]);
		p.tid = malloc(sizeof(p.tid) * p.n_philo);
		p.phork = malloc(sizeof(p.phork) * p.n_philo);
		p.tt_die_index = malloc(sizeof(int) * p.n_philo);
		p.t2die = ft_atoi(av[2]);
		p.t2eat = ft_atoi(av[3]);
		p.t2sleep = ft_atoi(av[4]);
		if (ac == 6)
			p.t_must_eat = ft_atoi(av[5]);
	}
	return (0);
}
