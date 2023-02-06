/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:24:32 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/06 12:44:17 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

void	*ft_memcopy(void *s1, void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s1)[i] = ((unsigned char *)s2)[i];
		i += 1;
	}
	return (s1);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(sizeof(size) * nitems + 1);
	if (!ptr)
		return (NULL);
	while (i < nitems)
	{
		ptr[i] = 0;
		i += 1;
	}
	return (ptr);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = ft_calloc(size, sizeof(ptr));
	new_ptr = ft_memcopy(new_ptr, ptr, size);
	return (new_ptr);
}
