/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_creation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:23:41 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/05 16:32:52 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

char	**ft_create_env_table(char **env, char *todo, char *cmd)
{
	t_arg	args;
	int		len;

	len = 0;
	while (env[len] != NULL)
		len += 1;
	args.env_args = malloc(sizeof(env) * len + 2);
	if (args.env_args)
	{
		len = 0;
		while (env[len] != NULL)
		{
			args.env_args[len] = malloc(sizeof(char) * ft_strlen(env[len], 0) + 1);
			ft_strcpy(env[len], args.env_args[len], 0);
			len += 1;
			if (env[len] == NULL && ft_strcmp("add", todo) == 0)
				args.env_args[len] = malloc(sizeof(char) * ft_strlen(cmd, 0) + 1);
		}
		if (ft_strcmp("add", todo) == 0 && cmd)
		{
			free(env);
			ft_strcpy(cmd, args.env_args[len++], 0);
		}
		args.env_args[len] = NULL;
	}
	return (args.env_args);
}

t_env	ft_create_env(char **env)
{
	t_env	p;
	int		i;

	i = 0;
	while (env[i] != 0)
		i += 1;
	p.arg = malloc(sizeof(char **) * i + 2);
	p.arg_value = malloc(sizeof(char **) * i + 2);
	if (p.arg)
	{
		i = -1;
		while (env[++i])
		{
			p.arg[i] = malloc(sizeof(char) * ft_strlen(env[i], 0) + 1);
			p.arg_value[i] = malloc(sizeof(char) * ft_strlen(env[i], 0) + 1);
			ft_strcpy(env[i], p.arg[i], '=');
			ft_strcpy(env[i] + ft_strlen(env[i], '=') + 1, p.arg_value[i], 0);
		}
		p.arg[i] = 0;
		p.arg_value[i] = 0;
	}
	return (p);
}
