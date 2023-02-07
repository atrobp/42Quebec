/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:31:30 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/07 10:55:56 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

void	*ft_memcopy(void *s1, void *s2, size_t n, unsigned char stopat)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s1)[i] = ((unsigned char *)s2)[i];
		i += 1;
		if (((unsigned char *)s2)[i] == stopat)
			break ;
	}
	return (s1);
}

size_t	ft_memlen(void *s1, unsigned char stopat)
{
	size_t	i;

	i = 0;
	while (((unsigned char *)s1)[i])
	{
		if (((unsigned char *)s1)[i] == stopat)
			break ;
		i += 1;
	}
	return (i);
}

void	*ft_memdup(void *ptr, void *ptr2, char stopat)
{
	void	*copy;

	copy = ft_calloc(ft_memlen(ptr, stopat), sizeof(ptr));
	ft_memcopy(copy, ptr, ft_memlen(ptr, stopat), stopat);
	if (((unsigned char *)ptr2)[0])
	{
		copy = ft_realloc(copy, ft_memlen(ptr, END) + ft_memlen(ptr2, END));
		ft_memcopy(copy + ft_memlen(copy, END), ptr2, ft_memlen(ptr2, END), END);
	}
	return (copy);
}

int	ft_memcmp(void *s1, void *s2)
{
	int	i;

	i = 0;
	while (((unsigned char *)s1)[i] && ((unsigned char *)s2)[i])
	{
		if (((unsigned char *)s2)[i] != ((unsigned char *)s1)[i])
		{
			return (0);
		}
		i += 1;
	}
	return (1);
}
