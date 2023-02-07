/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:03:22 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/07 00:42:39 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

// char	*ft_newgetenv(char *name, char **env)
// {
// 	char	*value;
// 	size_t	i;

// 	i = 0;
// 	while (env[i])
// 	{
// 		value = ft_newstrdup(env[i], '=');
// 		printf("%s %s\n", env[i], value);
// 		if (ft_strcmp(name, value))
// 		{
// 			return (env[i]);
// 		}
// 		i += 1;
// 	}
// 	return (NULL);
// }

void	*ft_trimstr(char *str)
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

int	main(int ac, char *av[], char **env)
{
	t_list	list;

	(void)ac;
	(void)av;
	(void)env;
	list = ft_env_import(env);
	list.command = ft_trimstr(readline("@minishelt> "));
	while (!ft_memcmp("exit", list.command))
	{
		system(list.command);
		list.command = ft_trimstr(readline("@minishelt> "));
	}
	return (0);
}

// t_list	ft_import_env(char **env)
// {
// 	t_list	mylist;
// 	size_t	i;

// 	i = 0;
// 	while (env[i])
// 		i += 1;
// 	mylist.len = i;
// 	mylist.env_vars = ft_calloc(i, sizeof(mylist.env_vars));
// 	i = 0;
// 	while (env[i])
// 	{
// 		mylist.env_vars[i] = ft_newstrdup(env[i], 0);
// 		i += 1;
// 	}
// 	if (getenv("USER") != NULL)
// 		mylist.user = getenv("USER");
// 	return (mylist);
// }
