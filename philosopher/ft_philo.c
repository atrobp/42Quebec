/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@42.quebec.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:02:46 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/22 23:55:59 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	*ft_philosopher(void *arg)
{
	t_list	*p;
	int		i;

	p = (t_list *)arg;
	i = -1;
	while (++i < p->n_philo)
	{
		printf("Philosopher %d is thinking\n", i + 1);
		p->tt_die_index[i] = 0;
		while (p->tt_die_index[i] < p->t_must_eat)
		{
			pthread_mutex_lock(&p->phork[i]);
			printf("Philosopher %d has taken a fork\n", i);
			pthread_mutex_lock(&p->phork[(i + 1) % p->n_philo]);
			printf("Philosopher %d has taken a fork\n", i);
			printf("Philosopher %d is eating\n", i);
			p->tt_die_index[i]++;
			usleep(p->t2eat * 1000);
			pthread_mutex_unlock(&p->phork[i]);
			pthread_mutex_unlock(&p->phork[(i + 1) % p->n_philo]);
			printf("Philosopher %d is sleeping\n", i);
			usleep(p->t2sleep * 1000);
			printf("Philosopher %d is thinking\n", i);
		}
	}
	pthread_exit(NULL);
}
