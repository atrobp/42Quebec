/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   builtins.c                                     ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/31 11:12:58 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/31 13:01:54 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_echo(t_shell *shell, char *cmd, char *arg)
{
	int	i;
	int	newline;

	(void)shell;
	(void)cmd;
	i = 0;
	newline = 1;
	if (arg[i] == '-')
	{
		while (arg[++i] == 'n')
		{
			newline = 0;
		}
		while (arg[i] == ' ')
			i++;
	}
	if (arg[i] == '\'' || arg[i] == '\"')
		i++;
	while (arg[i] != '\'' && arg[i] != '\"' && arg[i] != '\0')
	{
		printf("%c", arg[i]);
		i++;
	}
	if (newline == 1)
		printf("\n");
}
