/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocations_funcs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:24:32 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/09 13:35:58 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(size * nitems);
	if (!ptr)
		return (NULL);
	while (i < nitems * size)
	{
		((unsigned char *)ptr)[i] = 0;
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
	new_ptr = ft_memcopy(new_ptr, ptr, size, END);
	free(ptr);
	return (new_ptr);
}
