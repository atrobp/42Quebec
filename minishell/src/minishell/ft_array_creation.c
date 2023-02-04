/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_creation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:23:41 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/03 19:00:17 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

t_arg	ft_create_env_table(char **env, char *todo)
{
	t_arg	args;
	int		len;

	if (ft_strcmp(todo, "create") == 0)
		args.user = getenv("USER");
	len = 0;
	while (env[len] != NULL)
		len += 1;
	args.env_args = malloc(sizeof(env) * len + 2);
	if (args.env_args)
	{
		len = 0;
		while (env[len] != NULL)
		{
			args.env_args[len] = malloc(sizeof(char) * ft_strlen(env[len]) + 1);
			ft_strcpy(env[len], args.env_args[len]);
			len += 1;
		}
		if (ft_strcmp(todo, "add") == 0)
			args.env_args[len++] = malloc(sizeof(char) * ft_strlen("test") + 1);
		args.env_args[len] = NULL;
	}
	return (args);
}
