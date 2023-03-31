/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   strstr.c                                       ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/31 18:40:44 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/31 18:43:35 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == to_find[j])
		{
			i++;
			j++;
		}
		if (to_find[j] == '\0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_strnstr(char *str, char *to_find, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] && i < n)
	{
		while (str[i] == to_find[j])
		{
			i++;
			j++;
		}
		if (to_find[j] == '\0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}