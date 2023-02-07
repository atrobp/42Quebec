/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:56:52 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/06 22:11:36 by atopalli         ###   ########.fr       */
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
		list.env_vars[i] = ft_memdup(env[i], END);
		i += 1;
	}
	list.user = getenv("USER");
	return (list);
}

// t_list	ft_env(t_list *list, char *s1)
// {
// 	;
// }

// t_list	ft_env(t_list *list, char *s1)
// {
// 	;
// }

// t_list	ft_env(t_list *list, char *s1)
// {
// 	;
// }
