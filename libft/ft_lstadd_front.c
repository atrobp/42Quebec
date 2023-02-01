/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:53:29 by atopalli          #+#    #+#             */
/*   Updated: 2022/04/10 10:53:29 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list **copy;

	copy = malloc(sizeof(t_list));
	if (copy)
	{
		copy->new = new;
		copy->next = **lst;
		**lst = copy
	}
}
