/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrobp <atrobp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:05:31 by atopalli          #+#    #+#             */
/*   Updated: 2023/03/30 08:42:00 by atrobp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_id % 2 == 0)
		usleep(6);
	while (1)
	{
		if (philo->info->end == 1)
		{
			break ;
		}
		ft_eat(philo);
		ft_think(philo);
	}
	return (NULL);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->own_fork);
	ft_print(philo, philo->philo_id, "has taken a fork");
	pthread_mutex_lock(philo->neigtbour_fork);
	ft_print(philo, philo->philo_id, "has both forks");
	ft_print(philo, philo->philo_id, "is eating");
	ft_sleeptimer(philo->info->time2eat);
	philo->eaten += 1;
	philo->last_meal = ft_getcurrenttime();
	pthread_mutex_unlock(philo->neigtbour_fork);
	pthread_mutex_unlock(&philo->own_fork);
	ft_print(philo, philo->philo_id, "is sleeping");
	ft_sleeptimer(philo->info->time2sleep);
}

void	ft_print(t_philo *philo, unsigned int id, const char *action)
{
	pthread_mutex_lock(&philo->info->writing);
	printf("%lu %u %s\n", ft_getcurrenttime() - philo->info->start, id, action);
	pthread_mutex_unlock(&philo->info->writing);
}

void	ft_think(t_philo *philo)
{
	ft_print(philo, philo->philo_id, "is thinking");
}

void	*ft_reaper(void *arg)
{
	t_info			*info;
	unsigned int	i;

	info = (t_info *)arg;
	while (1)
	{
		i = 0;
		while (i < info->nbr_philo)
		{
			printf("--> %lu '#%d'\n", ft_getcurrenttime()
					- info->philos[i].last_meal, i + 1);
			if (ft_getcurrenttime()
				- info->philos[i].last_meal > info->time2die)
			{
				printf("--> %lu '#%d'\n", ft_getcurrenttime()
						- info->philos[i].last_meal, i + 1);
				exit(0);
			}
			i += 1;
		}
		if (info->end == 1)
		{
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}
