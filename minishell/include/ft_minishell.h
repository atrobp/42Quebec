/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:23:53 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/04 21:30:41 by atopalli         ###   ########.fr       */
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

typedef struct s_env
{
	char	**arg;
	char	**arg_value;
	char	*user;
}	t_env;

typedef struct s_arg
{
	char	*cmd_check[5];
	char	*local_args;
	char	**env_args;
	char	*user;
}		t_arg;

/*         src -- minishell         */
//ft_array_creation and addition
char	**ft_create_env_table(char **env, char *todo, char *command);
t_env	ft_create_env(char **env);

//ft_functions
void	ft_strcpy(char *src, char *dst, char stopat);
int		ft_strlen(char *str, char stopat);
char	*ft_getenv(char *name, t_env *env);
char	*ft_strdup(char *str, char *command);
int		ft_strcmp(char *s1, char *s2);

//ft_prompt_stuff
void	ft_writeprompt(t_env *args);

//ft_custom_op
int		ft_operation_caller(t_arg *args, char *command);
int		ft_print_env(t_arg *args, char *str);
int		ft_unset_add(t_arg *args, char *str);

#endif
