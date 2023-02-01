/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:50:47 by atopalli          #+#    #+#             */
/*   Updated: 2022/03/28 22:50:47 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static	int	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	size_t	i;

	if (s1 != 0 && s2 != 0)
	{
		concat = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
		if (concat)
		{
			i = 0;
			while (s1[i])
			{
				concat[i] = s1[i];
				i++;
			}
			i = 0;
			while (s2[i])
			{
				concat[ft_strlen(s1) + i] = s2[i];
				i++;
			}
			concat[ft_strlen(s1) + i] = '\0';
			return (concat);
		}
	}
	return (NULL);
}

static	int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}
