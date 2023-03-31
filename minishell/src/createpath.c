/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   createpath.c                                   ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/31 13:21:32 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/31 13:32:08 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * @brief Create a path with the command and the path
 * @param path The path to add the command
 * @param cmd The command to add to the path
 * @return The new path with the command
*/
char	*createpath(char *path, char *cmd)
{
	char	*newpath;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newpath = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(cmd) + 2));
	if (!newpath)
	{
		return (NULL);
	}
	while (path[i] != '\0')
	{
		newpath[i] = path[i];
		i++;
	}
	newpath[i++] = '/';
	while (cmd[j] != '\0')
	{
		newpath[i] = cmd[j];
		i++;
		j++;
	}
	newpath[i] = '\0';
	return (newpath);
}
