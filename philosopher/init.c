/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   init.c                                         ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/28 16:18:58 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/29 00:09:51 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_initinfo(t_info *info, const char **str)
{
	unsigned int	i;

	i = 0;
	info->nbr_philo = ft_atoi(str[1]);
	info->time2die = ft_atoi(str[2]);
	info->time2eat = ft_atoi(str[3]);
	info->time2sleep = ft_atoi(str[4]);
	info->nbr_eat = -1;
	if (str[5])
	{
		info->nbr_eat = ft_atoi(str[5]);
	}
	info->philos = malloc(sizeof(t_philo) * info->nbr_philo);
	if (!info->philos)
	{
		return (EXIT_FAILURE);
	}
	while (i < info->nbr_philo)
	{
		info->philos[i].philo_id = i + 1;
		info->philos[i].eaten = 0;
		info->philos[i].last_meal = ft_getcurrenttime();
		info->philos[i].info = info;
		i += 1;
	}
	info->start = ft_getcurrenttime();
	return (ft_initmutex(info));
}

int	ft_initthreads(t_info *info)
{
	unsigned int	i;

	i = 0;
	if (pthread_create(&info->reaper, NULL, &ft_reaper, info))
	{
		return (EXIT_FAILURE);
	}
	while (i < info->nbr_philo)
	{
		if (pthread_create(&info->philos[i].thread, NULL, &ft_routine,
				&info->philos[i]))
		{
			return (EXIT_FAILURE);
		}
		i += 1;
	}
	i = 0;
	while (i < info->nbr_philo)
	{
		if (pthread_join(info->philos[i].thread, NULL))
		{
			return (EXIT_FAILURE);
		}
		i += 1;
	}
	if (pthread_join(info->reaper, NULL))
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_initmutex(t_info *info)
{
	unsigned int	i;

	i = 0;
	if (pthread_mutex_init(&info->writing, NULL))
	{
		return (EXIT_FAILURE);
	}
	if (pthread_mutex_init(&info->dead, NULL))
	{
		return (EXIT_FAILURE);
	}
	while (i < info->nbr_philo)
	{
		if (pthread_mutex_init(&info->philos[i].own_fork, NULL))
		{
			return (EXIT_FAILURE);
		}
		if (i < info->nbr_philo - 1)
		{
			info->philos[i].neigtbour_fork = &info->philos[i + 1].own_fork;
		}
		i += 1;
	}
	info->philos[i - 1].neigtbour_fork = &info->philos[0].own_fork;
	return (ft_initthreads(info));
}
