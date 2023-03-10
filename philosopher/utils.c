/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   utils.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli atopalli@student.42quebec.com     ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/06 20:23:05 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/08 17:13:29 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief  ascii to integer
 * @param  *str: 
 * @retval actual integer or 0 if an error happen
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
		return (0);
	return (num);
}

/**
 * @brief  retreive current time in milliseconds
 * @retval time in ms
*/
unsigned long	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/**
 * @brief  sleep in millisecond
 * @param  time: time to sleep in ms
*/
void	ft_usleep(unsigned int time)
{
	unsigned long	start;

	start = ft_gettime();
	while (ft_gettime() - start < time)
		usleep(10);
}
