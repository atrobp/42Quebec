/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:01:53 by atopalli          #+#    #+#             */
/*   Updated: 2022/09/27 13:10:14 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ftstrlen(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			i += 1;
		}
	}
	return (i);
}
