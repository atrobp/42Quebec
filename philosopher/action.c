/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   action.c                                       ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli atopalli@student.42quebec.com     ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/08 00:24:55 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/08 01:30:53 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	ft_print(philo, philo->philo_id, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	ft_print(philo, philo->philo_id, "has both forks");
	ft_print(philo, philo->philo_id, "is eating");
	ft_usleep(philo->info->t2eat);
	philo->last_meal = ft_gettime();
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

void	ft_thinking(t_philo *philo)
{
	ft_print(philo, philo->philo_id, "is thinking");
}

void	ft_sleeping(t_philo *philo)
{
	ft_print(philo, philo->philo_id, "is sleeping");
	ft_usleep(philo->info->t2sleep);
}
