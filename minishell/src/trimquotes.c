/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   trimquotes.c                                   ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/31 16:58:23 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/31 18:35:39 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_trimquotes(char *str)
{
	int	i;

	i = 0;
	if (ft_cout_dquotes(str) == 0)
	{
		while (str[i])
		{
			if (str[i] == '\'' || str[i] == '\"')
			{
				str[i] = str[i + 1];
			}
			i += 1;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}

int	ft_cout_dquotes(char *str)
{
	int	i;
	int	singlequote;
	int	doublequote;

	singlequote = 0;
	doublequote = 0;
	i = 0;
	while (str[i])
	{
		if (singlequote > 0)
		{
			if (str[i] == '\'')
			{
				singlequote -= 1;
			}
		}
		if (doublequote > 0)
		{
			if (str[i] == '\"')
			{
				doublequote -= 1;
			}
		}
		if (str[i] == '\'')
		{
			singlequote += 1;
		}
		else if (str[i] == '\"')
		{
			doublequote += 1;
		}
		i += 1;
	}
	return (singlequote + doublequote);
}
