/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:25:16 by atopalli          #+#    #+#             */
/*   Updated: 2022/03/24 18:25:16 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n > 0)
	{
		if (src && dest)
		{
			n -= 1;
			((char *)dest)[n] = ((const char *)src)[n];
			ft_memmove(dest, src, n);
		}
	}
	return (dest);
}
