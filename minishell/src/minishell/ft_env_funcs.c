/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:56:52 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/09 14:06:09 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;

	new = malloc(sizeof(str) * 1000);
	if (!new || !str[0])
		return (NULL);
	for (i = 0; str[i]; i++)
		new[i] = str[i];
	new[i] = 0;
	return (new);
}

t_list	ft_env_import(char **env)
{
	t_list	list;
	size_t	i;

	i = 0;
	list.env_vars = NULL;
	if (env[0])
	{
		list.env_vars = malloc(sizeof(env) * 5) + 1;
		while (i < 5)
		{
			list.env_vars[i] = ft_memdup("hello", EMPTY, END);
			printf("%s\n", list.env_vars[i]);
			i += 1;
		}
		list.env_vars[i] = NULL;
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
	while (i < s->len)
	{
		temp[i] = ft_memdup(s->env_vars[i], EMPTY, END);
		free(s->env_vars[i]);
		i += 1;
	}
	temp[i] = ft_memdup(s->cmd + ft_memlen(s->cmd, ' '), EMPTY, END);
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
	while (i < s->len)
	{
		if (ft_memcmp("export", s->cmd))
		{
			printf("declare -x ");
		}
		printf("%s\n", s->env_vars[i]);
		i += 1;
	}
}
