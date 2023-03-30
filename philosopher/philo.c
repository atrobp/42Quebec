/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   philo.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/28 18:05:31 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/30 14:45:08 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
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
	ft_print(philo, philo->philo_id, "has taken a fork");
	ft_print(philo, philo->philo_id, "is eating");
	philo->last_meal = ft_getcurrenttime();
	ft_sleeptimer(philo->info->time2eat);
	philo->last_meal = ft_getcurrenttime();
	philo->eaten += 1;
	pthread_mutex_unlock(philo->neigtbour_fork);
	pthread_mutex_unlock(&philo->own_fork);
	ft_print(philo, philo->philo_id, "is sleeping");
	ft_sleeptimer(philo->info->time2sleep);
}

void	ft_print(t_philo *philo, unsigned int id, const char *action)
{
	if (ft_checkdead(philo))
	{
		return ;
	}
	pthread_mutex_lock(&philo->info->writing);
	printf("%lu %u %s\n", ft_getcurrenttime() - philo->info->start, id, action);
	pthread_mutex_unlock(&philo->info->writing);
}

void	ft_think(t_philo *philo)
{
	ft_print(philo, philo->philo_id, "is thinking");
}

void	ft_reaper(t_info *info)
{
	unsigned int i;

	while (1)
	{
		i = 0;
		while (i < info->nbr_philo)
		{
			if (ft_getcurrenttime()
				- info->philos[i].last_meal > info->time2die)
			{
				ft_print(&info->philos[i], i + 1, "is dead");
				return ;
			}
			i += 1;
		}
		if (info->end == true)
		{
			break ;
		}
		usleep(500);
	}
}