/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:59:55 by atopalli          #+#    #+#             */
/*   Updated: 2022/03/28 17:59:55 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	l;

	l = ft_strlen(s);
	while (l >= 0)
	{
		if (s[l] == (unsigned char)c)
		{
			return ((char *)&s[l]);
		}
		l--;
	}
	return (NULL);
}
