/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   philo.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli atopalli@student.42quebec.com     ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/06 22:34:17 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/08 01:27:45 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief  where philos make an action
 * @param  *arg: void * to philo struct
 * @retval None
*/
void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = ft_gettime();
	if (philo->philo_id % 2 == 0)
		ft_usleep(5);
	while (1 && philo->info->is_dead == false)
	{
		if (philo->last_meal - ft_gettime() > philo->info->t2die)
		{
			ft_print(philo, philo->philo_id, "is dead");
			pthread_mutex_lock(&philo->info->dead);
			philo->info->is_dead = true;
			pthread_mutex_unlock(&philo->info->dead);
		}
		ft_eating(philo);
		ft_thinking(philo);
	}
	return (NULL);
}

void	ft_print(t_philo *philo, unsigned int id, const char *action)
{
	pthread_mutex_lock(&philo->info->writing);
	printf("%lu %u %s\n", ft_gettime() - philo->info->start, id, action);
	pthread_mutex_unlock(&philo->info->writing);
}
