/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:03:29 by atopalli          #+#    #+#             */
/*   Updated: 2022/03/28 18:03:29 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	return (ft_memcmp(s1, s2, n));
}

static int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	c;

	c = 0;
	while (c < n && (((unsigned char *)s1)[c] || ((unsigned char *)s2)[c]))
	{
		if (((unsigned char *)s1)[c] != ((unsigned char *)s2)[c])
		{
			return (((unsigned char *)s1)[c] - ((unsigned char *)s2)[c]);
		}
		c++;
	}
	return (0);
}
