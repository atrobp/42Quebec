/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:16:42 by atopalli          #+#    #+#             */
/*   Updated: 2022/03/28 18:16:42 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void *calloc(size_t nmemb, size_t size);
{
	size_t	*fresh;

	fresh = malloc(sizeof(size));
	if (fresh != NULL)
	{
		return (fresh);
	}
	return (NULL);
}
