/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_stuff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:49:11 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/05 10:25:27 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

void	*ft_trimstr(char *str)
{
	int	i;
	int	copy;

	i = 0;
	copy = 0;
	while (str[i] == ' ' || str[i] == '	')
		i += 1;
	while (str[i])
	{
		str[copy] = str[i];
		i += 1;
		copy += 1;
		while (str[i] && str[i] <= ' ')
		{
			if (str[i + 1] > ' ')
				str[copy++] = ' ';
			i += 1;
		}
	}
	str[copy] = 0;
	return (str);
}

t_env	ft_sendcommand(t_env *args, char *cmd)
{
	args->special_cmds[0] = ft_strdup("unset", cmd + ft_strlen(cmd, ' ') + 1);
	if (ft_strcmp(cmd, args->special_cmds[0] == 0))
	{
		if (ft_getenv(cmd + ft_strlen(cmd, ' ') + 1, args) != NULL)
			*args = ft_delete_arg(args, cmd + ft_strlen(cmd, ' ') + 1);
	}
	else
		system(cmd);
	return (*args);
}

void	ft_writeprompt(t_env *args)
{
	char	*command;

	while (1)
	{
		write(1, KGRN, ft_strlen(KGRN, 0));
		write(1, args->user, ft_strlen(args->user, 0));
		write(1, KNRM, ft_strlen(KNRM, 0));
		command = ft_trimstr(readline("@minishelt> "));
		add_history(command);
	}
}
