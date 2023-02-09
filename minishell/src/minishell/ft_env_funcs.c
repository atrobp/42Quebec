/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:56:52 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/08 19:15:06 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

t_list	ft_env_import(char **env)
{
	t_list	list;
	size_t	i;

	i = 0;
	while (env[i])
		i += 1;
	list.len = i;
	list.env_vars = ft_calloc(list.len, sizeof(list.len));
	i = 0;
	while (env[i])
	{
		list.env_vars[i] = ft_memdup(env[i], EMPTY, END);
		i += 1;
	}
	return (list);
}

char	*ft_getenv(char *name, char **env)
{
	char	*s1;
	size_t	i;

	i = 0;
	while (env[i])
	{
		s1 = ft_memdup(env[i], EMPTY, '=');
		if (ft_memcmp(s1, name))
		{
			return (env[i] + ft_memlen(env[i], '='));
		}
		i += 1;
	}
	return (NULL);
}

void	ft_env_edit_add(t_list *s)
{
	char	**temp;
	size_t	i;

	temp = ft_calloc(s->len + 1, sizeof(temp));
	if (!temp)
		return ;
	i = 0;
	while (s->env_vars[i])
	{
		temp[i] = ft_memdup(s->env_vars[i], EMPTY, END);
		free(s->env_vars[i]);
		i += 1;
	}
	temp[i] = ft_memdup(s->command, EMPTY, END);
	free(s->env_vars);
	s->env_vars = temp;
}

void	ft_env_delete(t_list *s)
{
	if (s)
	{
		printf("UNSEETTTING");
	}
}

void	ft_env_print(t_list *s)
{
	size_t	i;

	i = 0;
	while (s->env_vars[i])
	{
		if (ft_memcmp("export", s->command))
		{
			printf("declare -x ");
		}
		printf("%s\n", s->env_vars[i]);
		i += 1;
	}
}
