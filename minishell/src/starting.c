/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   starting.c                                     ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/31 20:29:20 by atopalli            ██║███████╗          */
/*   Updated: 2023/04/04 10:15:56 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(t_shell *shell);

void	ft_startshell(t_shell *shell)
{
	if (shell == NULL)
		return ;
	while (shell->running)
	{
		shell->input = readline(PROMPT);
		ft_parser(shell);
	}
	ft_free(shell);
}

t_shell	*ft_initshell(char **envt)
{
	t_shell	*shell;
	int		i;

	shell = (t_shell *)malloc(sizeof(t_shell));
	if (shell == NULL)
		return (NULL);
	i = 0;
	while (envt[i])
		i += 1;
	shell->envt = (char **)malloc(sizeof(char *) * (i + 1));
	shell->env_size = i + 1;
	if (shell->envt == NULL)
		return (NULL);
	i = 0;
	while (envt[i])
	{
		shell->envt[i] = ft_strdup(envt[i]);
		if (ft_strncmp(envt[i], "PATH=", 5) == 0)
			shell->path = ft_split(envt[i] + 5, ':');
		i += 1;
	}
	shell->envt[i] = NULL;
	return (shell->running = RUNNING, shell);
}

void	ft_free(t_shell *shell)
{
	int	i;

	i = 0;
	free(shell->input);
	write(0, "exit\n", 5);
	while (shell->envt[i])
	{
		free(shell->envt[i]);
		i += 1;
	}
	free(shell->envt);
	i = 0;
	while (shell->path[i])
	{
		free(shell->path[i]);
		i += 1;
	}
	free(shell->path);
	free(shell);
}
