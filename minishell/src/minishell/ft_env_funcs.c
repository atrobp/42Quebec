/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:56:52 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/07 18:45:22 by atopalli         ###   ########.fr       */
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
	list.env_vars = ft_calloc(i, sizeof(env));
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

t_list	ft_env_edit_add(t_list *s)
{
	ft_realloc(s->env_vars, s->len++);
	s->env_vars[s->len] = ft_memdup(s->command + ft_memlen(s->command, ' '), EMPTY, END);
	printf(">>>%s\n", s->env_vars[s->len]);
	return (*s);
}

t_list	ft_env_delete(t_list *s)
{
	;
	return (*s);
}

t_list	ft_env_print(t_list *s)
{
	char	**temp;
	size_t	i;
	size_t	j;

	i = 0;
	temp = ft_calloc(s->len, sizeof(temp));
	while (i < s->len)
	{
		if (ft_memcmp("export", s->command))
		{
			j = 0;
			while (j < s->len - i)
			{
				if (s->env_vars[j][0] < s->env_vars[i][0])
				{
					temp[i] = ft_memdup(s->env_vars[j], EMPTY, END);
				}
				j += 1;
			}
			printf("declare -x %s\n", temp[i]);
		}
		else
			printf("%s\n", s->env_vars[i]);
		i += 1;
	}
	return (*s);
}
