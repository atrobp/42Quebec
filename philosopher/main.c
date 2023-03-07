/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   main.c                                         ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/04 19:55:21 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/06 23:13:18 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, const char **argv)
{
	int		i;
	t_info	info;

	i = 1;
	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	while (i < argc)
	{
		if (!(ft_atoi(argv[i]) > EXIT_SUCCESS))
			return (EXIT_FAILURE);
		i += 1;
	}
	ft_initinfo(&info, argv);
	return (EXIT_SUCCESS);
}
