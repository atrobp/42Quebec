/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_stuff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:49:11 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/03 21:11:02 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

void	ft_writeprompt(t_arg *args)
{
	char	*command;

	while (1)
	{
		write(1, KGRN, ft_strlen(KGRN));
		write(1, args->user, ft_strlen(args->user));
		write(1, KNRM, ft_strlen(KNRM));
		command = ft_trimme(readline("@minishelt> "));
	}
}
