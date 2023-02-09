/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:03:22 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/08 21:36:28 by atopalli         ###   ########.fr       */
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
	void		(*ptr_func[3])(t_list *) = {ft_env_print, ft_env_edit_add, ft_env_delete};

	p->specialcmd[0] = ft_memdup("export", EMPTY, END);
	p->specialcmd[1] = ft_memdup("export ", p->cmd + ft_memlen(p->cmd, ' '), END);
	p->specialcmd[2] = ft_memdup("unset ", p->cmd + ft_memlen(p->cmd, ' '), END);
	i = 0;
	while (i < 4)
	{
		if (ft_memcmp(p->cmd, p->specialcmd[i]))
		{
			ptr_func[i](p);
			break ;
		}
		i += 1;
	}
	if (i == 4)
		system(p->cmd);
	free(p->cmd);
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
		list.cmd = ft_trimcmd(readline("minishelt> "));
		if (!ft_memcmp("exit", list.cmd))
			ft_check_cmd(&list);
		else
			break ;
	}
	free(list.cmd);
	free(list.env_vars);
	return (0);
}
