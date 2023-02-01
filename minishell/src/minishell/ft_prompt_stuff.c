/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_stuff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:49:11 by atopalli          #+#    #+#             */
/*   Updated: 2023/01/31 23:53:49 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

void	ft_writeprompt(t_arg *args)
{
	char	*command;
	char	*prev_command;
	int		call;

	call = -1;
	while (1)
	{
		write(1, KGRN, ft_strlen(KGRN));
		write(1, args->user, ft_strlen(args->user));
		write(1, KNRM, ft_strlen(KNRM));
		command = readline("@minishelt>");
		if (command[0] != ' ')
		{
			if (++call == 0)
			{
				prev_command = ft_strdup(command);
				add_history(prev_command);
			}
			else if (ft_strcmp(prev_command, command))
			{
				free(prev_command);
				prev_command = ft_strdup(command);
				add_history(prev_command);
			}
		}
		command = ft_trimme(command);
		system(command);
	}
}
