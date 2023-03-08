/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   philo.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/06 22:34:17 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/07 23:43:22 by atopalli            ╚═╝╚══════╝.qc       */
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
	while (1)
	{
	}
	return (NULL);
}

void	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->eating);
	
}
