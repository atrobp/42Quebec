/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   init.c                                         ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/04 20:14:47 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/05 16:42:56 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	ft_initdata(t_data *data, const char *argv[])
{
	int	i;

	i = -1;
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->n_eat = 0;
	if (argv[5])
		data->n_eat = ft_atoi(argv[5]);
	data->start = ft_gettime();
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philo)
		return (EXIT_FAILURE);
	while (++i < (int)data->n_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].n_eat = 0;
		data->philo[i].last_eat = 0;
	}
	if (ft_initmutex(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_initthreads(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

unsigned int	ft_initmutex(t_data *data)
{
	unsigned int	i;

	i = 0;
	if (pthread_mutex_init(&data->eat, NULL) != 0)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&data->sleep, NULL) != 0)
		return (EXIT_FAILURE);
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->philo[i].left_fork, NULL) != 0)
			return (EXIT_FAILURE);
		if (i < data->n_philo - 1)
			data->philo[i].right_fork = &data->philo[i + 1].left_fork;
		i++;
	}
	data->philo[i - 1].right_fork = &data->philo[0].left_fork;
	return (EXIT_SUCCESS);
}

unsigned int	ft_initthreads(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, &ft_philo,
				(void *)&data) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
