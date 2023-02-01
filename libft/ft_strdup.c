/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:22:54 by atopalli          #+#    #+#             */
/*   Updated: 2022/03/28 18:22:54 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static	int	ft_strlen(const char *s);

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		i;

	copy = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (copy != NULL && str != NULL)
	{
		i = 0;
		while (str[i])
		{
			copy[i] = str[i];
			i++;
		}
		copy[i] = 0;
		return (copy);
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
