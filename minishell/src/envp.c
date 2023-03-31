/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   envp.c                                         ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/30 21:10:30 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/31 11:49:15 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * @brief Create a new envrionment
 * @param envp The environment to copy from
 * @return Shell struct with the new environment and the path
*/
t_env	ft_envp(char **envp)
{
	t_env	env;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	env.envp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			env.path = ft_split(envp[i] + 5, ':');
		}
		env.envp[i] = ft_strdup(envp[i]);
		i++;
	}
	env.envp[i] = NULL;
	return (env);
}
