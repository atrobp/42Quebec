/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:23:53 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/01 00:18:12 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "readline/history.h"
# include "readline/readline.h"

# define KGRN "\x1B[32m"
# define KNRM "\x1B[0m"

typedef struct s_arg
{
	char	**local_args;
	char	**env_args;
	char	*user;
}		t_arg;

/*         src -- minishell         */
//ft_array_creation
char	**ft_create_env_table(char **env);

//ft_functions
void	ft_strcpy(char *src, char *dst);
int		ft_strlen(char *str);
void	*ft_trimme(char *str);
char	*ft_strdup(char *str);
int		ft_strcmp(char *s1, char *s2);

//ft_prompt_stuff
void	ft_writeprompt(t_arg *args);

#endif
