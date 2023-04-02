/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   split.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/31 21:24:24 by atopalli            ██║███████╗          */
/*   Updated: 2023/04/02 10:06:54 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split(char *s, char c)
{
	char	**array;
	int		i;
	int		j;

	i = 0;
	j = -1;
	array = (char **)malloc(sizeof(char *) * (ft_strlen(s, 0) + 1));
	if (!array)
		return (NULL);
	array[i] = (char *)malloc(sizeof(char) * (ft_strlen(s, 0) + 1));
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s != c)
			array[i][++j] = *s;
		else
		{
			array[i][++j] = '\0';
			if (array[i][0])
			{
				i += 1;
				array[i] = (char *)malloc(sizeof(char) * (ft_strlen(s, 0) + 1));
			}
			j = -1;
		}
		s++;
	}
	array[i][++j] = '\0';
	return (array[i + 1] = NULL, array);
}
