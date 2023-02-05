/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:31:30 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/04 19:20:03 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

void	ft_strcpy(char *src, char *dst, char stopat)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i += 1;
		if (src[i] == stopat)
			break ;
	}
	dst[i] = 0;
}

int	ft_strlen(char *str, char stopat)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == stopat)
			break ;
		len += 1;
	}
	return (len);
}

int	ft_getenv(char *name, char **env_name)
{
	int	i;

	i = 0;
	while (env_name[i])
	{
		if (ft_strcmp(name, env_name[i]) == 0)
			return (0);
		i += 1;
	}
	return (1);
}

char	*ft_strdup(char *str, char *command)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(str) * ft_strlen(str, 0) + 1);
	if (str[0] > ' ')
	{
		while (str[i])
		{
			dup[i] = str[i];
			i += 1;
		}
		while (*command)
		{
			dup[i] = *command;
			i += 1;
			command += 1;
		}
		dup[i] = 0;
		return (dup);
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s2[i] != s1[i])
			break ;
		i += 1;
	}
	return (s2[i] - s1[i]);
}
