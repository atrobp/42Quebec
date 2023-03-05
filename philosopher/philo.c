/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   philo.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/04 20:32:30 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/05 16:51:16 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		// ft_eat(philo);
		// ft_print(philo, philo->id, "is eating");
		// ft_sleep(philo);
		// printf("philo %d is thinking\n", philo->id);
		ft_print(philo, philo->id, "is thinking");
		exit(0);
	}
	return (NULL);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	// ft_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	printf("philo %d has both forks\n", philo->id);
	// ft_print(philo, "has taken a fork");
	// printf("philo %d is eating\n", philo->id);
	ft_print(philo, philo->id, "is eating");
	philo->last_eat = ft_gettime();
	// ft_usleep(philo->data->t_eat);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->n_eat++;
}

void	ft_sleep(t_philo *philo)
{
	ft_print(philo, philo->id, "is sleeping");
	// ft_usleep(philo->data->t_sleep);
}
