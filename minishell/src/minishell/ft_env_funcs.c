/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:56:52 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/11 08:42:17 by atopalli         ###   ########.fr       */
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
	list.env_vars = malloc(sizeof(char **) * (i + 1));
	if (!list.env_vars)
		return (list);
	i = 0;
	while (env[i])
	{
		list.env_vars[i] = ft_memdup(env[i], EMPTY, END);
		i += 1;
	}
	list.env_vars[i] = NULL;
	list.len = i;
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
			free(s1);
			return (env[i] + ft_memlen(env[i], '='));
		}
		free(s1);
		i += 1;
	}
	return (NULL);
}

bool	ft_env_edit(t_list *s)
{
	size_t	i;
	char	*var;

	i = 0;
	var = ft_memdup(s->cmd + 7, EMPTY, '=');
	if (!ft_getenv(var, s->env_vars))
	{
		free(var);
		return (false);
	}
	while (s->env_vars[i])
	{
		if (ft_memcmp(s->env_vars[i] + ft_memlen(s->env_vars[i], '='), ft_getenv(var, s->env_vars)))
		{
			free(s->env_vars[i]);
			s->env_vars[i] = ft_memdup(s->cmd + 7, EMPTY, END);
			free(var);
		}
		i += 1;
	}
	return (true);
}

void	ft_env_edit_add(t_list *s)
{
	char	**temp;
	size_t	i;

	if (ft_env_edit(s))
		return ;
	temp = malloc(sizeof(temp) * (s->len + 2));
	if (!temp)
		return ;
	i = 0;
	while (s->env_vars[i])
	{
		temp[i] = ft_memdup(s->env_vars[i], EMPTY, END);
		free(s->env_vars[i]);
		i += 1;
	}
	temp[i] = ft_memdup(s->cmd + ft_memlen(s->cmd, ' '), EMPTY, END);
	temp[i + 1] = NULL;
	s->len += 1;
	free(s->env_vars);
	s->env_vars = temp;
}

void	ft_env_delete(t_list *s)
{
	size_t	i;
	char	*value;

	i = 0;
	value = ft_getenv(s->cmd + 6, s->env_vars);
	if (value)
	{
		while (s->env_vars[i])
		{
			if (ft_memcmp(s->env_vars[i] + ft_memlen(s->env_vars[i], '='), value))
			{
				free(s->env_vars[i]);
				break ;
			}
			i += 1;
		}
		while (s->env_vars[i])
		{
			s->env_vars[i] = s->env_vars[i + 1];
			i += 1;
		}
		s->env_vars[i] = NULL;
	}
}

void	ft_env_print(t_list *s)
{
	size_t	i;

	i = 0;
	while (s->env_vars[i])
	{
		if (ft_memcmp("export", s->cmd))
			printf("export -x ");
		printf("%s\n", s->env_vars[i]);
		i += 1;
	}
}
