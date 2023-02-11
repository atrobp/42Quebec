/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:03:22 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/10 20:13:41 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

int	main(int ac, char **av, char **env)
{
	t_list	list;

	(void)ac;
	(void)av;
	(void)env;
	list = ft_env_import(env);
	if (list.env_vars)
	{
		while (1)
		{
			list.cmd = ft_trimcmd(readline("\x1B[32mminishelt> \x1B[0m"));
			if (ft_memcmp("exit", list.cmd))
				break ;
			ft_check_cmd(&list);
		}
		ft_exit(&list);
	}
	return (0);
}

void	ft_exit(t_list *list)
{
	size_t	i;

	i = 0;
	while (list->env_vars[i])
	{
		free(list->env_vars[i]);
		i += 1;
	}
	free(list->cmd);
	free(list->env_vars);
}

void	ft_valid_and_send(char **input, char **path)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		printf(">>%s\n", path[i]);
		i += 1;
	}
	i = 0;
	while (path[i])
	{
		printf("%s\n", path[i]);
		i += 1;
	}
}
