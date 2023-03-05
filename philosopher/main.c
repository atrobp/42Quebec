/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   main.c                                         ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/04 19:55:21 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/05 17:08:49 by atopalli            ╚═╝╚══════╝.qc       */
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
		if (!(ft_atoi(argv[i]) > EXIT_SUCCESS))
			return (EXIT_FAILURE);
	}
	if (ft_initdata(&data, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

unsigned int	ft_atoi(const char *str)
{
	unsigned int	res;
	unsigned int	i;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0' || str[0] == '0')
		return (0);
	return (res);
}

void	ft_print(t_philo *philo, unsigned int id, char *str)
{
	// unsigned long	time;
	// time = ft_gettime() - philo->data->start;
	// pthread_mutex_lock(&philo->data->print);
	// printf("%ld %d %s\n", time, id, str);
	(void)philo;
	printf("%u %s\n", id, str);
	// pthread_mutex_unlock(&philo->data->print);
}

unsigned long	ft_gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}
