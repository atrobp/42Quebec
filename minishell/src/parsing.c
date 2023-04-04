/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   parsing.c                                      ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/04/01 16:01:59 by atopalli            ██║███████╗          */
/*   Updated: 2023/04/04 10:16:27 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	ft_firstcheck(char *input);
int		ft_checkquotes(char *s);

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
		printf("%s: syntax error near '%c'\n", PROMPT2, c);
		free(shell->input);
		return ;
	}
	c = ft_checkquotes(shell->input);
	if (c != 1)
	{
		printf("%s: syntax error unclosed quotes\n", PROMPT2);
		free(shell->input);
		return ;
	}
	if (ft_tokenize(shell, ft_split(shell->input, '|')) == 0)
		return ;
}

char	ft_firstcheck(char *s)
{
	int	i;
	int	fchar;

	fchar = 0;
	i = 0;
	while (s[i])
	{
		if ((fchar == 0) && (s[i] == '|' || s[i] == '&'))
			return (s[i]);
		if (s[i] == '&' && s[i + 1] == '|')
			return (s[i + 1]);
		if (s[i] == '|' || s[i] == '&')
			if (s[i + 2 == '|' || s[i + 2] == '&'])
				return (s[i + 2]);
		if (s[i] == '>' && s[i + 1] == '<')
			return (s[i + 1]);
		if (s[i] > ' ')
			fchar = 1;
		i += 1;
	}
	return (0);
}

int	ft_checkquotes(char *s)
{
	int	i;
	int	dq;
	int	sq;

	i = 0;
	dq = 0;
	sq = 0;
	while (s[i])
	{
		if (s[i] == '\"')
			dq += 1;
		if (s[i] == '\'')
			sq += 1;
		i += 1;
	}
	if (dq % 2 == 0 && sq % 2 == 0)
		return (1);
	return (0);
}
