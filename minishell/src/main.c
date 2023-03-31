/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   main.c                                         ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/30 21:06:24 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/31 15:06:16 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	char	**split;
	t_shell	shell;
	int		i;

	(void)argc;
	(void)argv;
	(void)envp;
	shell.env = ft_envp(envp);
	while (1)
	{
		i = 0;
		input = readline(PROMPT);
		add_history(input);
		split = ft_split(input, '|');
		ft_parsecmd(split, &shell.cmd);
		while (shell.cmd.cmds[i])
		{
			printf("cmd:'%s' args:'%s'", shell.cmd.cmds[i], shell.cmd.args[i]);
			printf("\n");
			ft_execve(&shell, shell.cmd.cmds[i], shell.cmd.args[i]);
			i++;
		}
		free(input);
		free(split);
	}
	return (0);
}
