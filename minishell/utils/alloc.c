/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   alloc.c                                        ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/31 21:58:47 by atopalli            ██║███████╗          */
/*   Updated: 2023/04/02 09:42:42 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
	{
		return (NULL);
	}
	while (i < count * size)
	{
		((char *)ptr)[i] = 0;
		i += 1;
	}
	return (ptr);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;
	size_t	i;

	i = 0;
	new = malloc(size);
	if (!new)
	{
		return (NULL);
	}
	while (((char *)ptr)[i])
	{
		((char *)new)[i] = ((char *)ptr)[i];
		i += 1;
	}
	while (i < size)
	{
		((char *)new)[i] = 0;
		i += 1;
	}
	free(ptr);
	return (new);
}
