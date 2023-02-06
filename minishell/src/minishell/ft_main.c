/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:03:22 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/05 21:52:49 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

int	main(int ac, char *av[], char *env[])
{
	t_env	args;

	(void)ac;
	(void)av;
	(void)env;
	// args = ft_create_env(env);
	// args.user = ft_getenv("USER", &args);
	args.user = getenv("USER");
	printf("%s", args.user);
	// ft_writeprompt(&args);
	return (0);
}
