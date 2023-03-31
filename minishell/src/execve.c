/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   execve.c                                       ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/31 10:55:37 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/31 15:05:54 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * @brief Execute the command
 * @param shell The shell struct
 * @param cmd The command to execute
 * @param arg The argument of the command
 * ! Reduce the number of lines
 * @return 0
*/
int	ft_execve(t_shell *shell, char *cmd, char *arg)
{
	int		pid;
	int		status;
	char	*path;
	char	*args[3];
	int		i;

	i = 0;
	if (ft_strlen(arg) == 0)
		args[0] = NULL;
	else
		args[0] = cmd;
	args[1] = arg;
	args[2] = NULL;
	if (ft_isbuiltin(shell) == 0)
	{
		while (shell->env.path[i])
		{
			path = createpath(shell->env.path[i], cmd);
			if (access(path, F_OK) == 0)
			{
				pid = fork();
				if (pid == 0)
				{
					execve(path, args, shell->env.envp);
				}
				else
				{
					waitpid(pid, &status, 0);
				}
				free(path);
				break ;
			}
			free(path);
			i++;
		}
	}
	return (0);
}

/**
 * @brief Check if the command is a builtin
 * @param shell The shell struct
 * ! Reduce the number of lines
 * @return 1 if the command is a builtin, 0 if not 
*/
int	ft_isbuiltin(t_shell *shell)
{
	char	*builtins[5];
	void	(*funcptr[1])(t_shell *, char *, char *);
	int		i;
	int		j;

	i = 0;
	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	funcptr[0] = ft_echo;
	while (shell->cmd.cmds[i])
	{
		j = 0;
		while (j < 5)
		{
			if (ft_strncmp(shell->cmd.cmds[i], builtins[j],
					ft_strlen(builtins[j])) == 0)
			{
				funcptr[i](shell, shell->cmd.cmds[i], shell->cmd.args[i]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
