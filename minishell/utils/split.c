/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   split.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/30 21:22:19 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/31 01:14:57 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * @brief split a string into an array of strings
 * @param str string to split
 * @param set character to split
 * @return array of strings
*/
char	**ft_split(char *str, char c)
{
	char	**array;
	int		i;
	int		j;

	i = 0;
	j = -1;
	array = (char **)malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (!array)
		return (NULL);
	array[i] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (*str)
	{
		if (*str != c)
			array[i][++j] = *str;
		else
		{
			array[i][++j] = '\0';
			i++;
			j = -1;
			array[i] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		}
		str++;
	}
	array[i][++j] = '\0';
	return (array[i + 1] = NULL, array);
}
