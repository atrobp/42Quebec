/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:05:36 by atopalli          #+#    #+#             */
/*   Updated: 2022/03/24 18:05:36 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (n > 0 && (dest != NULL || src != NULL))
	{
		n--;
		((char *)dest)[n] = ((char *)src)[n];
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
