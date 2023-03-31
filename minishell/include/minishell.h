/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   minishell.h                                    ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/30 21:07:09 by atopalli            ██║███████╗          */
/*   Updated: 2023/03/31 01:17:04 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PROMPT "minishell> "

# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_env
{
	char	**envp;
	char	**path;
}			t_env;

typedef struct s_cmd
{
	char	**cmds;
	char	**args;
}			t_cmd;

typedef struct s_shell
{
	t_env	env;
	t_cmd	cmd;
}			t_shell;

// dealing with commands

void		ft_parsecmd(char **input, t_cmd *cmd);

// dealing with envp

t_env		ft_envp(char **envp);
char		*ft_getenv(char *key, char);

// dealing with strings

char		**ft_split(char *s, char c);
char		*ft_strdup(const char *s1);
int			ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_putchar(char c);
void		ft_putstr(char *s);

// dealing with builtins

void		ft_echo(char *cmd, char *arg);
void		ft_cd(char *cmd, char *arg);
void		ft_pwd(char *cmd, char *arg);
void		ft_export(char *cmd, char *arg);
void		ft_unset(char *cmd, char *arg);
int			ft_isbuiltin(t_env *env, t_cmd *cmd);

#endif
