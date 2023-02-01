/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:43:47 by atopalli          #+#    #+#             */
/*   Updated: 2022/03/28 17:43:47 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static	int	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	res;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	res = len_src + size;
	i = 0;
	if (size > len_dst)
	{
		res = len_src + len_dst;
	}
	while (src[i] && (len_dst + 1) < size)
	{
		dst[len_dst] = src[i];
		len_dst++;
		i++;
	}
	dst[len_dst] = '\0';
	return (res);
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
