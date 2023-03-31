/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   parsecmd.c                                     ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/30 22:56:32 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/30 23:18:38 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
 * @brief Parse the input and separate the commands and arguments
 * @param input The input to parse
 * @param cmd The struct to store the parsed input
 * ! TODO Reduce the numbers of lines 
*/
void	ft_parsecmd(char **input, t_cmd *cmd)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	cmd->args = (char **)malloc(sizeof(char *) * (ft_strlen(input[i]) + 1));
	cmd->cmds = (char **)malloc(sizeof(char *) * (ft_strlen(input[i]) + 1));
	cmd->args[k] = (char *)malloc(sizeof(char) * (ft_strlen(input[i]) + 1));
	cmd->cmds[k] = (char *)malloc(sizeof(char) * (ft_strlen(input[i]) + 1));
	while (input[i])
	{
		while (input[i][j] == ' ')
		{
			j++;
		}
		while (input[i][j] != ' ' && input[i][j] != '\0')
		{
			cmd->cmds[k][l] = input[i][j];
			j++;
			l++;
		}
		cmd->cmds[k][l] = '\0';
		while (input[i][j] == ' ')
		{
			j++;
		}
		l = 0;
		while (input[i][j] != ' ' && input[i][j] != '\0')
		{
			cmd->args[k][l] = input[i][j];
			j++;
			l++;
		}
		cmd->args[k][l] = '\0';
		k++;
		cmd->args[k] = (char *)malloc(sizeof(char) * (ft_strlen(input[i]) + 1));
		cmd->cmds[k] = (char *)malloc(sizeof(char) * (ft_strlen(input[i]) + 1));
		j = 0;
		l = 0;
		i++;
	}
	cmd->args[k] = NULL;
	cmd->cmds[k] = NULL;
}
