/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   free.c                                         ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/04/02 17:50:00 by atopalli            ██║███████╗          */
/*   Updated: 2023/04/02 17:53:36 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_freeptrptr(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
	{
		return ;
	}
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_freeptr(char *ptr)
{
	if (ptr)
	{
		free(ptr);
	}
}
