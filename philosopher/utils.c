/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   utils.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli atopalli@student.42quebec.com     ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/06 20:23:05 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/07 01:24:10 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

// get start time in milliseconds and store it in number pointer
void	ft_gettime(unsigned long *number)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	*number = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	printf("start time: %ld", *number);
}
