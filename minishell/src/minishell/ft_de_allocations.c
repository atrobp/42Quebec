/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_de_allocations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:24:32 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/05 21:44:30 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(sizeof(size) * nitems + 1);
	if (ptr)
	{
		while (i <= nitems)
		{
			ptr[i] = 0;
			i += 1;
		}
		return (ptr);
	}
	return (NULL);
}

void	*ft_realloc(void *ptr, size_t size)
{
	free(ptr);
	return (ft_calloc(size, sizeof(ptr)));
}
