/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   philo.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/05 20:52:20 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/06 17:03:58 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_tread_chec_dead(void *arg)
{
	t_data			*data;
	unsigned int	i;

	data = arg;
	i = 0;
	while (1)
	{
		if (i > data->n_philo)
			i = 0;
		pthread_mutex_lock(&data->philo[i].data->eat);
		if (data->philo[i].last_eat - ft_gettime() > data->philo[i].data->t_die)
		{
			pthread_mutex_lock(&data->dead);
			ft_print(&data->philo[i], "died");
			data->is_dead = 1;
			pthread_mutex_unlock(&data->dead);
			return (NULL);
		}
		pthread_mutex_unlock(&data->philo[i].data->eat);
		i++;
	}
	return (NULL);
}

void	*ft_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = ft_gettime();
	if (philo->id % 2 == 0)
		ft_usleep(2);
	while (1 && philo->data->is_dead == 0)
	{
		if (ft_eat(philo) == 1)
			return (NULL);
		if (ft_think(philo) == 1)
			return (NULL);
		if (philo->last_eat - ft_gettime() > philo->data->t_die)
		{
			pthread_mutex_lock(&philo->data->dead);
			ft_print(philo, "died");
			philo->data->is_dead = 1;
			pthread_mutex_unlock(&philo->data->dead);
		}
	}
	return (NULL);
}

int	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	if (philo->data->is_dead == 1)
		return (1);
	ft_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	if (philo->data->is_dead == 1)
		return (1);
	ft_print(philo, "has taken a fork");
	philo->last_eat = ft_gettime();
	if (philo->data->is_dead == 1)
		return (1);
	ft_print(philo, "is eating");
	ft_usleep(philo->data->t_eat);
	philo->n_eat++;
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	ft_sleep(philo);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	if (philo->data->is_dead == 1)
		return (1);
	ft_print(philo, "is sleeping");
	ft_usleep(philo->data->t_sleep);
	return (0);
}

int	ft_think(t_philo *philo)
{
	if (philo->data->is_dead == 1)
		return (1);
	ft_print(philo, "is thinking");
	return (0);
}

void	ft_usleep(unsigned int time)
{
	unsigned long	start;

	start = ft_gettime();
	while (ft_gettime() - start < time)
		usleep(100);
}
