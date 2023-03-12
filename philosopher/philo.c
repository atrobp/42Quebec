/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   philo.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/06 22:34:17 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/10 08:07:50 by atopalli            ╚═╝╚══════╝.qc       */
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
	if (philo->philo_id % 2 == 0)
		ft_usleep(10);
	while (1)
	{
		if (ft_gettime() - philo->last_meal > philo->info->t2die)
		{
			ft_print(philo, philo->philo_id, "is dead");
			return (NULL);
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
