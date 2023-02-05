/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_stuff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:49:11 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/05 16:29:21 by atopalli         ###   ########.fr       */
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
	int		i;
	t_env	(*cmd_func[4])(t_env *, char *);
	args->special_cmds[0] = ft_strdup("unset ", cmd + ft_strlen(cmd, ' ') + 1);
	args->special_cmds[1] = "export";
	args->special_cmds[2] = ft_strdup("export ", cmd + ft_strlen(cmd, ' ') + 1);
	args->special_cmds[3] = "env";
	cmd_func[0] = ft_delete_arg;
	cmd_func[1] = ft_print_env;
	cmd_func[2] = ft_add_env;
	cmd_func[3] = ft_print_env;
	i = 0;
	while (i < 4)
	{
		if (ft_strcmp(cmd, args->special_cmds[i]) == 0)
			return (cmd_func[i](args, cmd + ft_strlen(cmd, ' ') + 1));
		i += 1;
	}
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
		*args = ft_sendcommand(args, command);
	}
}
