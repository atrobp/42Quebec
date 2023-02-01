/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:31:30 by atopalli          #+#    #+#             */
/*   Updated: 2023/01/31 22:51:39 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

void	ft_strcpy(char *src, char *dst)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = 0;
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len += 1;
	}
	return (len);
}

void	*ft_trimme(char *str)
{
	int	i;
	int	j;
	int	copy;

	j = 0;
	i = 0;
	while (str[i] <= ' ')
		i += 1;
	j = ft_strlen(str);
	while (str[--j] <= ' ')
		;
	if (i != 0 || j != ft_strlen(str) - 1)
	{
		copy = -1;
		while (i <= j)
		{
			str[++copy] = str[i];
			i += 1;
		}
		str[++copy] = 0;
	}
	return (str);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(str) * ft_strlen(str) + 1);
	if (str[0] > ' ')
	{
		while (str[i])
		{
			dup[i] = str[i];
			i += 1;
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
