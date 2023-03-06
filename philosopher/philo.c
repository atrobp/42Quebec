/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   philo.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/05 20:52:20 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/06 11:21:46 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = ft_gettime();
	if (philo->id % 2 == 0)
		ft_usleep(100);
	while (1)
	{
		ft_eat(philo);
		ft_think(philo);
		if (philo->last_eat - ft_gettime() > philo->data->t_die)
		{
			ft_print(philo, "died");
			return (NULL);
		}
		return (NULL);
	}
}
void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	ft_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	ft_print(philo, "has taken a fork");
	ft_print(philo, "is eating");
	ft_usleep(philo->data->t_eat);
	philo->n_eat++;
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->last_eat = ft_gettime();
	ft_sleep(philo);
}

void	ft_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	ft_usleep(philo->data->t_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_print(philo, "is thinking");
}

void	ft_usleep(unsigned int time)
{
	unsigned long	start;

	start = ft_gettime();
	while (ft_gettime() - start < time)
		usleep(100);
}
