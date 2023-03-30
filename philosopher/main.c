/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   main.c                                         ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/28 13:51:48 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/30 14:48:48 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char const *argv[])
{
	int		i;
	t_info	info;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		printf("Error: Invalid number of arguments!\n");
		return (EXIT_FAILURE);
	}
	while (i < argc)
	{
		if (!(ft_atoi(argv[i]) > EXIT_SUCCESS))
		{
			return (EXIT_FAILURE);
		}
		i += 1;
	}
	ft_initinfo(&info, argv);
	ft_reaper(&info);
	ft_freeall(&info);
	return (EXIT_SUCCESS);
}
