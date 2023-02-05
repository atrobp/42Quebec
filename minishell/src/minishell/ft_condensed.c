/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condensed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:33:33 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/04 21:43:07 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

int	ft_str_len_cpy_diff(char *s1, char *s2, char todo)
{
	int	i;

	i = 0;
	while (todo == 'd')
	{
		if (!(s2[i] || s1[i]) || s2[i] != s1[i])
			return (s2[i] - s1[i]);
		i += 1;
	}
	while (s2[i])
	{
		if (todo == 'c')
			s1[i] = s2[i];
		i += 1;
	}
	if (todo == 'c')
		s1[i] = 0;
	return (i);
}
