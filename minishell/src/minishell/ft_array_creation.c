/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_creation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:23:41 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/02 22:38:05 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

t_arg	ft_create_env_table(char **env, char *todo)
{
	t_arg	args;
	int		arg_len;

	args.cmd_check[0] = "unset";
	args.cmd_check[1] = "export";
	args.cmd_check[2] = "env";
	args.cmd_check[3] = "exit";
	if (ft_strcmp(todo, "create") == 0)
		args.user = getenv("USER");
	arg_len = 0;
	while (env[arg_len] != NULL)
		arg_len += 1;
	args.env_args = malloc(sizeof(env) * arg_len + 2);
	if (args.env_args)
	{
		arg_len = 0;
		while (env[arg_len] != NULL)
		{
			args.env_args[arg_len] = malloc(sizeof(char) * ft_strlen(env[arg_len]) + 1);
			ft_strcpy(env[arg_len], args.env_args[arg_len]);
			arg_len += 1;
		}
		if (ft_strcmp(todo, "add") == 0)
			args.env_args[arg_len++] = malloc(sizeof(char) * ft_strlen("test") + 1);
		args.env_args[arg_len] = NULL;
	}
	return (args);
}
