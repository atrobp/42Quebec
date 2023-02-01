/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:07:03 by atopalli          #+#    #+#             */
/*   Updated: 2022/04/04 14:07:03 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ftstlen(char const *s, unsigned int *len);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	if (s)
	{
		i = ftstlen(s, &len);
		str = malloc(sizeof(char) * len + 1);
		if (str)
		{
			while (s[i])
			{
				str[i] = f(i, s[i]);
				i += 1;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}

static	int	ftstlen(char const *s, unsigned int *len)
{
	*len = 0;
	while (s[*len])
	{
		*len += 1;
	}
	return (0);
}
