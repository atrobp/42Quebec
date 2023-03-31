/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   getenv.c                                       ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/31 10:49:16 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/31 10:54:26 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * @brief Get the value of a variable from our environment
 * @param shell The shell struct
 * @param var The variable to get the value from
 * @return The value of the variable or NULL if it doesn't exist
*/
char	*ft_getenv(t_shell *shell, char *var)
{
	int	i;
	int	j;

	i = 0;
	while (shell->env.envp[i])
	{
		j = 0;
		while (shell->env.envp[i][j] == var[j])
		{
			j++;
		}
		if (shell->env.envp[i][j] == '=')
		{
			return (shell->env.envp[i] + j + 1);
		}
		i++;
	}
	return (NULL);
}
