/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   parsing.c                                      ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/04/01 16:01:59 by atopalli            ██║███████╗          */
/*   Updated: 2023/04/02 10:07:02 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	ft_firstcheck(char *input);
int		ft_tokenize(t_shell *shell, char **array);

void	ft_parser(t_shell *shell)
{
	char	c;

	if (shell->input == NULL)
	{
		shell->running = EXIT;
		return ;
	}
	c = ft_firstcheck(shell->input);
	if (c != 0)
	{
		printf("minishell: syntax error near '%c'\n", c);
		free(shell->input);
		return ;
	}
	if (ft_tokenize(shell, ft_split(shell->input, '|')) == 0)
		return ;
}

char	ft_firstcheck(char *input)
{
	int	i;
	int	fchar;

	fchar = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '|' || input[i] == '&')
		{
			if (fchar == 0)
				return (input[i]);
			if (input[i + 2] == '|' || input[i + 2] == '&')
				return (input[i + 2]);
		}
		if (input[i] > ' ')
		{
			fchar = 1;
		}
		i += 1;
	}
	return (0);
}

int	ft_veriftokens(char **array)
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
	if (ft_veriftokens(array) == 0)
	{
		printf("minishell: syntax error near unexpected token '|'\n");
		free(shell->input);
		return (0);
	}
	return (1);
}
