/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:40:52 by atopalli          #+#    #+#             */
/*   Updated: 2022/03/28 16:40:52 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static	int	ft_strlen(const char *s);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!(dst || src))
	{
		return (0);
	}
	if (size > 0)
	{
		i = 0;
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return ((size_t)ft_strlen(src));
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
