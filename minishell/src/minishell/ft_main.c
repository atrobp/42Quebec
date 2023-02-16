/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:03:22 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/16 16:21:19 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

static void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_signal_on(void)
{
	signal(SIGINT, handle_signal);
}

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
			signal(SIGINT, handle_signal);
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
	size_t	j;
	char	*tmp;

	i = 0;
	while (input[i])
	{
		j = 0;
		tmp = ft_memdup(input[i], EMPTY, ' ');
		printf("CMD --> %s\n", tmp);
		while (path[j])
		{
			printf("PATH --> %s/%s\n", path[j], tmp);
			j += 1;
		}
		free(tmp);
		i += 1;
	}
}
