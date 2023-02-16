/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:43:30 by anshimiy          #+#    #+#             */
/*   Updated: 2023/02/13 10:11:29 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_minishell.h"

# define DBQUOTE 34
# define SQUOTE 39
# define PIPE 124
# define SPACE 32
# define DOLLAR 36
# define DOUBLEPIPE 123
# define DOUBLEAMPERSAND 125
// # define CTRLC 135 or 3?

typedef enum e_shell_status {
    RUNNING,
    OVER,
} t_shell_status;


typedef struct s_env
{
	char			**envp;
	char			**env_vars;
	char			*pwd;
	char			*oldpwd;
    char			*cmd;
	char			*expand;
	struct s_env	*next;
}					t_env;

typedef struct s_shell
{
	char			*prompt;
	char			**argv;
	t_shell_status	shell_status;
	int				cd_count;
	char			**envp;
	t_env			*env;
}					t_shell;

void    ft_init_shell(t_shell *shell, char **envp)
{
    if (shell->env && envp && *envp)
	{
		shell->env->envp = envp;
		shell->env->env_vars = ft_dup_arr(envp);
		shell->env->pwd = ft_get_env_variable(shell->env, "PWD");
		shell->env->oldpwd = ft_get_env_variable(shell->env, "OLDPWD");
		if (shell->env->env_vars && shell->env->pwd && shell->env->oldpwd)
		{
			get_envp(envp, false);
			ft_set_variable(shell->env);
			return (true);
		}
	}
	return (false);
}