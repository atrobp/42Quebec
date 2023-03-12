/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   action.c                                       ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/08 00:24:55 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/10 09:52:18 by atopalli            ╚═╝╚══════╝.qc       */
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
	ft_sleeping(philo);
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

void	*ft_isdead(void *arg)
{
	unsigned int	i;
	t_info			*info;

	info = arg;
	while (1)
	{
		i = 0;
		while (i < info->nbr_philo)
		{
			if (600 > info->t2die)
			{
				printf("i is dead");
				printf("%u\n", i);
				exit(0);
			}
			printf("%u %u\n", i, info->t2die);
			i += 1;
		}
	}
	return (NULL);
}
