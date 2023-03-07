/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   philo.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/06 22:34:17 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/06 23:22:09 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(t_philo *philo)
{
	printf("%lu %u\n", philo->info->start, philo->philo_id);
	return (NULL);
}
