/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   main.c                                         ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli atopalli@student.42quebec.com     ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/04 19:55:21 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/08 17:49:24 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_info *info)
{
	unsigned int	i;

	i = 0;
	pthread_mutex_destroy(&info->writing);
	pthread_mutex_destroy(&info->dead);
	if (info->philos)
	{
		while (i < info->nbr_philo)
		{
			pthread_mutex_destroy(&info->philos[i].left_fork);
			i += 1;
		}
	}
	if (info->philos)
		free(info->philos);
}

int	main(int argc, const char *argv[])
{
	int		i;
	t_info	info;

	i = 0;
	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	while (++i < argc)
	{
		if (!(ft_atoi(argv[i]) > EXIT_SUCCESS))
			return (EXIT_FAILURE);
	}
	ft_initinfo(&info, argv);
	return (ft_free(&info), EXIT_SUCCESS);
}
