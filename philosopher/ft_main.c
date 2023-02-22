/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:47:50 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/22 13:23:00 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	main(int ac, char **av)
{
	t_list	p;
	int		i;

	i = 0;
	if (ac >= 5 && ac <= 6)
	{
		p = ft_philo_check(ac, av);
		if (p.valid == true)
		{
			ft_philo_init(&p);
		}
	}
	return (0);

}

void	ft_philo_init(t_list *p)
{
	int	i;

	i = -1;
	while (++i < p->n_philo)
	{
		pthread_mutex_init(&p->phork[i], NULL);
	}
	i = -1;
	while (++i < p->n_philo)
	{
		pthread_create(&p->tid[i], NULL, ft_philosopher, (void *)p);
	}
	i = -1;
	while (++i < p->n_philo)
	{
		pthread_join(p->tid[i], NULL);
	}
	i = -1;
	while (++i < p->n_philo)
	{
		pthread_mutex_destroy(&p->phork[i]);
	}
}

t_list	ft_philo_check(int ac, char **av)
{
	t_list	p;
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atoi(av[i]) <= 0)
		{
			p.valid = false;
			return (p);
		}
	}
	i = 0;
	p.t_must_eat = -1;
	p.n_philo = ft_atoi(av[1]);
	p.phork = malloc(sizeof(p.phork) * p.n_philo);
	p.tid = malloc(sizeof(p.tid) * p.n_philo);
	p.tt_die_index = malloc(sizeof(int) * p.n_philo);
	p.t2die = ft_atoi(av[2]);
	p.t2eat = ft_atoi(av[3]);
	p.t2sleep = ft_atoi(av[4]);
	if (ac == 6)
		p.t_must_eat = ft_atoi(av[5]);
	p.valid = true;
	return (p);
}

int	ft_atoi(char *str)
{
	int	i;
	int	final;

	i = 0;
	final = 0;
	if (str[0] != '-' && str[0] != '0')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			final = final * 10 + (str[i] - '0');
			i += 1;
		}
		return (final);
	}
	return (0);
}
