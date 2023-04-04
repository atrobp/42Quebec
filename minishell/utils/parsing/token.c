/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   token.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/04/02 18:00:49 by atopalli            ██║███████╗          */
/*   Updated: 2023/04/04 10:02:29 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_verifytokens(char **array)
{
	int	i;
	int	toret;

	i = 0;
	toret = 1;
	while (array[i])
	{
		if (array[i][0] == '\0')
			toret = 0;
		i += 1;
	}
	if (toret == 0)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i += 1;
		}
		free(array);
	}
	return (toret);
}

int	ft_tokenize(t_shell *shell, char **array)
{
	if (ft_verifytokens(array) == 0)
	{
		printf("minishell: syntax error near unexpected token '|'\n");
		free(shell->input);
		return (0);
	}
	ft_create_cmds(shell, array);
	ft_freeptrptr(array);
	return (1);
}
