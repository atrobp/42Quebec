/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:31:35 by atopalli          #+#    #+#             */
/*   Updated: 2022/03/28 21:31:35 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	tofi;

	if (!(needle[0]))
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < n)
	{
		tofi = 0;
		while (haystack[i + tofi] == needle[tofi] && i + tofi < n)
		{
			if (needle[tofi + 1] == '\0')
			{
				return ((char *)haystack + i);
			}
			tofi++;
		}
		++i;
	}
	return (NULL);
}
