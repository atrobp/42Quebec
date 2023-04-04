/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   cmds.c                                         ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/04/02 18:30:10 by atopalli            ██║███████╗          */
/*   Updated: 2023/04/04 10:02:19 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_getarraylen(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}

int	ft_moveforward(char *input, int c)
{
	int	i;

	i = 0;
	while (input[i] == c && input[i])
	{
		i += 1;
	}
	return (i);
}

void	ft_createarrays(t_shell *shell, char **array)
{
	int	i;

	i = 0;
	shell->cmds = (char **)malloc(sizeof(char *) * ft_getarraylen(array) + 1);
	shell->args = (char **)malloc(sizeof(char *) * ft_getarraylen(array) + 1);
	if (!shell->cmds || !shell->args)
	{
		ft_freeptrptr(array);
		printf("Error: malloc failed\n");
		shell->running = EXIT;
		return ;
	}
	while (array[i])
	{
		shell->cmds[i] = malloc(sizeof(char) * ft_strlen(array[i], 0) + 1);
		shell->args[i] = malloc(sizeof(char) * ft_strlen(array[i], 0) + 1);
		if (!shell->cmds[i] || !shell->args[i])
		{
			ft_freeptrptr(array);
			printf("Error: malloc failed\n");
			shell->running = EXIT;
			return ;
		}
		i += 1;
	}
	shell->cmds[i] = NULL;
	shell->args[i] = NULL;
}

void	ft_createargs(t_shell *shell, char *s, int index)
{
	(void)shell;
	(void)s;
	(void)index;
}

void	ft_create_cmds(t_shell *shell, char **array)
{
	int		i;
	int		j;
	char	fchar;

	i = 0;
	fchar = ' ';
	ft_createarrays(shell, array);
	while (array[i])
	{
		j = 0;
		j += ft_moveforward(array[i], ' ');
		if (array[i][j] == '\'' || array[i][j] == '\"')
		{
			fchar = array[i][j];
			while (array[i][j] == fchar)
				j += 1;
		}
		ft_strccpy(shell->cmds[i], array[i] + j, fchar);
		ft_createargs(shell, array[i] + ft_strlen(array[i], 0), i);
		i += 1;
	}
}
