/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   init.c                                         ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli atopalli@student.42quebec.com     ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/06 20:40:44 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/08 00:57:34 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief  set philos data and time in main
 * @param  *info: struct info pointer
 * @param  **av: main second parameter
 * @retval initmutex if malloc doesnt fail
*/
int	ft_initinfo(t_info *info, const char **av)
{
	unsigned int	i;

	i = 0;
	info->nbr_philo = ft_atoi(av[1]);
	info->t2die = ft_atoi(av[2]);
	info->t2eat = ft_atoi(av[3]);
	info->t2sleep = ft_atoi(av[4]);
	info->n_must_eat = 0;
	if (av[5])
		info->n_must_eat = ft_atoi(av[5]);
	info->philos = malloc(sizeof(t_philo) * info->nbr_philo);
	if (!info->philos)
		return (EXIT_FAILURE);
	while (i < info->nbr_philo)
	{
		info->philos[i].philo_id = i + 1;
		info->philos[i].last_meal = 0;
		info->philos[i].info = info;
		info->philos[i].eat_time = 0;
		i += 1;
	}
	info->start = ft_gettime();
	return (ft_initmutex_threads(info));
}

/**
 * @brief  thread and mutex creation
 * @param  *info: struct info pointer
 * @retval EXIT_SUCCESS if everthing went right
*/
int	ft_initmutex_threads(t_info *info)
{
	int	i;

	info->is_dead = false;
	if (pthread_mutex_init(&info->writing, NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&info->dead, NULL))
		return (EXIT_FAILURE);
	i = -1;
	while (++i < (int)info->nbr_philo)
	{
		if (pthread_create(&info->philos[i].thread, NULL, &ft_routine,
				&info->philos[i]))
			return (EXIT_FAILURE);
		if (pthread_mutex_init(&info->philos[i].left_fork, NULL))
			return (EXIT_FAILURE);
		if (i < (int)info->nbr_philo - 1)
			info->philos[i].right_fork = &info->philos[i + 1].left_fork;
	}
	info->philos[i - 1].right_fork = &info->philos[0].left_fork;
	i = -1;
	while (++i < (int)info->nbr_philo)
		if (pthread_join(info->philos[i].thread, NULL))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
