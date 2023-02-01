/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:43:29 by atopalli          #+#    #+#             */
/*   Updated: 2022/03/28 18:43:29 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static	unsigned int	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (s != 0)
	{
		substr = malloc(sizeof(char) * len + 1);
		if (substr)
		{
			i = 0;
			if (start < ft_strlen(s) && len <= ft_strlen(s))
			{
				while (i < len)
				{
					substr[i] = s[start + i];
					i++;
				}
			}
			substr[i] = '\0';
			return (substr);
		}
	}
	return (0);
}

static	unsigned int	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}
