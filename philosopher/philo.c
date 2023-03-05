/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   philo.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/04 20:32:30 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/04 23:02:04 by atopalli            ╚═╝╚══════╝.qc       */
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
		ft_sleep(philo);
		ft_print(philo, philo->id, "is thinking");
	}
	return (NULL);
}

// void	ft_eat(t_philo *philo)
// {
//     pthread_mutex_lock(&philo->left_fork);
//     ft_print(philo, "has taken a fork");
//     pthread_mutex_lock(philo->right_fork);
//     ft_print(philo, "has taken a fork");
//     ft_print(philo, "is eating");
//     philo->last_eat = ft_gettime();
//     ft_usleep(philo->data->t_eat);
//     pthread_mutex_unlock(&philo->left_fork);
//     pthread_mutex_unlock(philo->right_fork);
//     philo->n_eat++;
// }

void	ft_sleep(t_philo *philo)
{
	ft_print(philo, philo->id, "is sleeping");
	// ft_usleep(philo->data->t_sleep);
}
