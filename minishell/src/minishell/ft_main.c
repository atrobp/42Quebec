/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:03:22 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/07 22:02:49 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

void	*ft_trimcmd(char *str)
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

void	ft_check_cmd(t_list *p)
{
	size_t			i;
	static void		(*ptr_func[4])(t_list *) = {ft_env_print,
		ft_env_edit_add, ft_env_print, ft_env_delete};

	i = 0;
	p->specialcmd[0] = ft_memdup("export", EMPTY, END);
	p->specialcmd[1] = ft_memdup("export ", EMPTY, END);
	p->specialcmd[2] = ft_memdup("env", EMPTY, END);
	p->specialcmd[3] = ft_memdup("unset ", EMPTY, END);
	if (ft_memchr(p->command, ' '))
	{
		p->specialcmd[1] = ft_realloc(p->specialcmd[1],
				ft_memlen(p->command, END));
		p->specialcmd[3] = ft_realloc(p->specialcmd[3],
				ft_memlen(p->command, END));
		p->specialcmd[1] = ft_memdup("export ", p->command
				+ ft_memlen(p->command, ' '), END);
		p->specialcmd[3] = ft_memdup("unset ", p->command
				+ ft_memlen(p->command, ' '), END);
	}
	while (++i < 4)
	{
		if (ft_memcmp(p->command, p->specialcmd[i]))
		{
			ptr_func[i](p);
			break ;
		}
	}
	if (i == 4)
		system(p->command);
	free(p->command);
}

int	main(int ac, char **av, char **env)
{
	t_list	list;

	(void)ac;
	(void)av;
	(void)env;
	list = ft_env_import(env);
	while (1)
	{
		list.command = ft_trimcmd(readline("minishelt> "));
		if (!ft_memcmp("exit", list.command))
			ft_check_cmd(&list);
		else
			break ;
	}
	free(list.command);
	free(list.env_vars);
	return (0);
}
