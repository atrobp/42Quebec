/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:03:22 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/02 19:19:08 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

int	main(int ac, char *av[], char *env[])
{
	t_arg	args;

	(void)ac;
	(void)av;
	(void)env;
	args = ft_create_env_table(env, "create");
	ft_writeprompt(&args);
	return (0);
}
