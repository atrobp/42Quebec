/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_custom_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:57:29 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/05 13:03:27 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

t_env	ft_add_env(t_env *args, char *str)
{
	char	*temp;

	temp = malloc(sizeof(char*) * ft_strlen(str, '=') + 1);
	ft_strcpy(str, temp, '=');
}

t_env	ft_delete_arg(t_env *args, char *removeme)
{
	int	i;

	i = 0;
	while (args->arg[i])
	{
		if (ft_strcmp(removeme, args->arg[i]) == 0)
		{
			printf("%s", args->arg[i]);
			while (args->arg[i])
			{
				args->arg[i] = args->arg[i + 1];
				args->arg_value[i] = args->arg_value[i + 1];
				i += 1;
			}
		}
		i += 1;
	}
	return (*args);
}

t_env	ft_print_env(t_env *args, char *cmd)
{
	int	i;

	i = 0;
	while (args->arg[i] != NULL)
	{
		if (ft_strcmp("export", cmd) == 0)
			write(1, "export -x ", 10);
		printf("%s=%s\n", args->arg[i], args->arg_value[i]);
		i += 1;
	}
	return (*args);
}

int	ft_operation_caller(t_arg *args, char *command)
{
	int		i;
	// int		(*ptr_func[5])(t_arg *, char *);
	int		len;

	len = ft_strlen(command, 0);
	while (command[--len] > ' ')
		;
	i = 0;
	// ptr_func[1] = ft_print_env;
	// ptr_func[2] = ft_print_env;
	// ptr_func[4] = ft_add_env;
	args->cmd_check[0] = "unset";
	args->cmd_check[1] = "export";
	args->cmd_check[2] = "env";
	args->cmd_check[3] = "exit";
	args->cmd_check[4] = ft_strdup("export ", command + len + 1);
	while (i < 5)
	{
		if (ft_strcmp(args->cmd_check[i], command) == 0)
			// return (ptr_func[i](args, command + len + 1));
		i += 1;
	}
	return (i);
}
