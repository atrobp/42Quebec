/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_stuff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:49:11 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/02 19:33:14 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

void	ft_writeprompt(t_arg *args)
{
	int		i;
	char	*command;

	while (1)
	{
		i = 0;
		write(1, KGRN, ft_strlen(KGRN));
		write(1, args->user, ft_strlen(args->user));
		write(1, KNRM, ft_strlen(KNRM));
		command = ft_trimme(readline("@minishelt>"));
		if (ft_strcmp(command, "export") == 0)
		{
			while (args->env_args[i])
			{
				write(1, args->env_args[i], ft_strlen(args->env_args[i]));
				write(1, "\n", 1);
				i += 1;
			}
		}
		else
			system(command);
	}
}
