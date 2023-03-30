/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   utils.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/28 16:20:41 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/28 22:36:05 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief string to intger
 * @param *str string to convert from
 * @returns converted intger from str
*/
int	ft_atoi(const char *str)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i += 1;
	}
	if (str[i] || str[0] == '0')
	{
		return (0);
	}
	return (num);
}

/**
 * @returns current time in milliseconds
*/
unsigned long	ft_getcurrenttime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/**
 * @brief sleep program in milliseconds
*/
void	ft_sleeptimer(unsigned int time)
{
	unsigned long	start;

	start = ft_getcurrenttime();
	while (ft_getcurrenttime() - start - time)
	{
		usleep(10);
	}
}

/**
 * @brief free everything that is allocated
*/
void	ft_freeall(t_info *info)
{
	unsigned int	i;

	i = 0;
	pthread_mutex_destroy(&info->writing);
	// pthread_mutex_destroy(&info->reaper);
	if (info->philos)
	{
		while (i < info->nbr_philo)
		{
			pthread_mutex_destroy(&info->philos[i].own_fork);
		}
		i += 1;
	}
	if (info->philos)
	{
		free(info->philos);
	}
}
