/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:57:29 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/03 19:10:28 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

void	ft_print_env(t_arg *args)
{
	int	i;

	i = 0;
	while (args->env_args[i] != NULL)
	{
		write(1, args->env_args[i], ft_strlen(args->env_args[i]));
		write(1, "\n", 1);
		i += 1;
	}
}

int	ft_operation_caller(t_arg *args, char *command)
{
	int	i;

	i = 0;
	args->cmd_check[0] = "unset";
	args->cmd_check[1] = "export";
	args->cmd_check[2] = "env";
	args->cmd_check[3] = "exit";
	while (i < 4)
	{
		if (ft_strcmp(args->cmd_check[i], command) == 0)
		{
			ft_print_env(args);
			break ;
		}
		i += 1;
	}
	return (i);
}
