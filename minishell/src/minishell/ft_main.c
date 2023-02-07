/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:03:22 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/07 11:13:25 by atopalli         ###   ########.fr       */
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

t_list	ft_check_cmd(t_list *p)
{
	size_t			i;
	static t_list	(*ptr_func[4])(t_list *) = {ft_env_print,
		ft_env_edit_add, ft_env_print, ft_env_delete};

	i = -1;
	p->specialcmd[0] = ft_memdup("export", EMPTY, END);
	p->specialcmd[1] = ft_memdup("export ", p->command, END);
	p->specialcmd[2] = ft_memdup("env", EMPTY, END);
	p->specialcmd[1] = ft_memdup("unset ", p->command, END);
	while (++i < 3)
	{
		if (ft_memcmp(p->command, p->specialcmd[i]))
		{
			*p = ptr_func[i](p);
			break ;
		}
	}
	if (i == 3)
		system(p->command);
	free(p->command);
	return (*p);
}

int	main(int ac, char *av[], char **env)
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
	for (size_t i = 0; list.env_vars[i]; i++)
	{
		printf("%s\n", list.env_vars[i]);
		free(list.env_vars[i]);
	}
	free(list.env_vars);
	free(list.command);
	return (0);
}
