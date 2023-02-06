/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:03:22 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/06 13:13:05 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

t_list	ft_import_env(char **env);
char	*ft_newstrdup(char *str);

char	*ft_newgetenv(char *name, char **env)
{
	char	*value;
	bool	found;
	size_t	i;

	i = 0;
	found = 0;
	while (env[i])
	{
		value = ft_calloc(ft_strlen(env[i], 0), sizeof(value));
		ft_strcpy(env[i], value, '=');
		if (ft_strcmp(name, value))
		{
			found = 1;
			free(value);
			break ;
		}
		free(value);
		i += 1;
	}
	if (found == true)
		return (env[i] + ft_strlen(env[i], '=') + 1);
	return (NULL);
}

int	main(int ac, char *av[], char *env[])
{
	t_list	args;

	(void)ac;
	(void)av;
	(void)env;
	args = ft_import_env(env);
	args.user = ft_newgetenv("USER", args.env_vars);
	ft_writeprompt(&args);
	return (0);
}

char	*ft_newstrdup(char *str)
{
	char	*copy;

	copy = ft_calloc(ft_strlen(str, 0), sizeof(str));
	ft_strcpy(str, copy, 0);
	return (copy);
}

t_list	ft_import_env(char **env)
{
	t_list	mylist;
	size_t	i;

	i = 0;
	while (env[i])
		i += 1;
	mylist.env_vars = ft_calloc(i, sizeof(mylist.env_vars));
	i = 0;
	while (env[i])
	{
		mylist.env_vars[i] = ft_newstrdup(env[i]);
		i += 1;
	}
	mylist.user = getenv("USER");
	return (mylist);
}
