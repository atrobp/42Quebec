/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:23:53 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/06 13:05:21 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "readline/history.h"
# include "readline/readline.h"

# define KGRN "\x1B[32m"
# define KNRM "\x1B[0m"

typedef struct s_list
{
	char	**env_vars;
	char	**local_vars;
	char	*user;
	char	*command;
}		t_list;

typedef struct s_env
{
	char	**arg;
	char	**arg_value;
	char	*user;
	char	*special_cmds[5];
}	t_env;

typedef struct s_arg
{
	char	*cmd_check[5];
	char	*local_args;
	char	**env_args;
	char	*user;
}		t_arg;

/*         src -- minishell         */
//ft_array creation, addition, edition and print
char	**ft_create_env_table(char **env, char *todo, char *command);
t_env	ft_create_env(char **env);
t_env	ft_delete_arg(t_env *args, char *removeme);
t_env	ft_print_env(t_env *args, char *cmd);
t_env	ft_add_env(t_env *args, char *cmd);

//ft_functions
void	ft_strcpy(char *src, char *dst, char stopat);
int		ft_strlen(char *str, char stopat);
char	*ft_getenv(char *name, t_env *env);
char	*ft_strdup(char *str, char *command);
int		ft_strcmp(char *s1, char *s2);

//ft_prompt_stuff
void	ft_writeprompt(t_list *args);

//ft_custom_op
int		ft_operation_caller(t_arg *args, char *command);
int		ft_unset_add(t_arg *args, char *str);

//ft_allocation
void	*ft_calloc(size_t nitems, size_t size);
void	*ft_realloc(void *ptr, size_t size);
void	*ft_memcopy(void *s1, void *s2, size_t n);

#endif
