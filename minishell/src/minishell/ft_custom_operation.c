/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:57:29 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/04 15:05:50 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

int	ft_add_env(t_arg *args, char *str)
{
	int		len;

	len = ft_strlen(str);
	while (str[--len] > ' ')
		;
	args->env_args = ft_create_env_table(args->env_args, "add", str + len + 1);
	return (0);
}


int	ft_print_env(t_arg *args, char *str)
{
	int	i;

	i = 0;
	while (args->env_args[i] != NULL)
	{
		if (ft_strcmp("export", str) == 0)
			write(1, "export -x ", 10);
		write(1, args->env_args[i], ft_strlen(args->env_args[i]));
		write(1, "\n", 1);
		i += 1;
	}
	return (0);
}

int	ft_operation_caller(t_arg *args, char *command)
{
	int		i;
	int		(*ptr_func[5])(t_arg *, char *);
	int		len;

	len = ft_strlen(command);
	while (command[--len] > ' ')
		;
	i = 0;
	ptr_func[1] = ft_print_env;
	ptr_func[2] = ft_print_env;
	ptr_func[4] = ft_add_env;
	args->cmd_check[0] = "unset";
	args->cmd_check[1] = "export";
	args->cmd_check[2] = "env";
	args->cmd_check[3] = "exit";
	args->cmd_check[4] = ft_strdup("export ", command + len + 1);
	while (i < 5)
	{
		if (ft_strcmp(args->cmd_check[i], command) == 0)
			return (ptr_func[i](args, command + len + 1));
		i += 1;
	}
	return (i);
}
