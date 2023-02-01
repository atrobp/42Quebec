/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_creation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:23:41 by atopalli          #+#    #+#             */
/*   Updated: 2023/01/31 18:17:03 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

char	**ft_create_env_table(char **env)
{
	int		arg_len;
	char	**temp;

	arg_len = 0;
	while (env[arg_len] != NULL)
		arg_len += 1;
	temp = malloc(sizeof(env) * arg_len + 1);
	if (temp)
	{
		arg_len = 0;
		while (env[arg_len] != NULL)
		{
			temp[arg_len] = malloc(sizeof(char) * ft_strlen(env[arg_len]) + 1);
			ft_strcpy(env[arg_len], temp[arg_len]);
			arg_len += 1;
		}
		return (temp);
	}
	return (NULL);
}
