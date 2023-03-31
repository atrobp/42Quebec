/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   main.c                                         ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/30 21:06:24 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/31 01:32:32 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	char	**split;
	t_shell	shell;

	(void)argc;
	(void)argv;
	(void)envp;
	shell.env = ft_envp(envp);
	while (1)
	{
		input = readline(PROMPT);
		add_history(input);
		split = ft_split(input, '|');
		ft_parsecmd(split, &shell.cmd);
	}
	return (0);
}
