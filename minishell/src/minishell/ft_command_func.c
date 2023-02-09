/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:14:02 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/09 19:30:06 by atopalli         ###   ########.fr       */
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
	static void		(*ptr_func[3])(t_list *)
		= {ft_env_print, ft_env_edit_add, ft_env_delete};

	ft_setspecial_cmd(p);
	i = 0;
	while (i < 3)
	{
		if (ft_memcmp(p->cmd, p->spec_cmd[i]))
		{
			ptr_func[i](p);
			break ;
		}
		free(p->spec_cmd[i]);
		i += 1;
	}
	if (i == 3)
		system(p->cmd);
	while (i < 3)
		free(p->spec_cmd[i++]);
	free(p->cmd);
}

void	ft_setspecial_cmd(t_list *p)
{
	p->spec_cmd[0] = ft_memdup("export", EMPTY, END);
	p->spec_cmd[1] = ft_memdup("export ", EMPTY, END);
	p->spec_cmd[2] = ft_memdup("unset ", EMPTY, END);
	p->spec_cmd[3] = NULL;
	if (ft_memchr(p->cmd, ' '))
	{
		free(p->spec_cmd[1]);
		free(p->spec_cmd[2]);
		p->spec_cmd[1] = ft_memdup("export ", p->cmd + 7, END);
		p->spec_cmd[2] = ft_memdup("unset ", p->cmd + 6, END);
	}
}
