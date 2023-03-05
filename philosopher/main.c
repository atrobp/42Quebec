/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   main.c                                         ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli atopalli@student.42quebec.com     ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/04 19:55:21 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/05 11:30:19 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, const char *argv[])
{
	int		i;
	t_data	data;

	i = 0;
	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) == 0)
			return (EXIT_FAILURE);
	}
	if (ft_initdata(&data, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

unsigned int	ft_atoi(const char *str)
{
	unsigned int	res;

	res = 0;
	if (*str == '0' && res == 0)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res);
}

void	ft_print(t_philo *philo, unsigned int id, char *str)
{
	// unsigned long	time;
	// time = ft_gettime() - philo->data->start;
	// pthread_mutex_lock(&philo->data->print);
	// printf("%ld %d %s\n", time, id, str);
	(void)philo;
	printf("%d %s\n", id, str);
	// pthread_mutex_unlock(&philo->data->print);
}

unsigned long	ft_gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}
