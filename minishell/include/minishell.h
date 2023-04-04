/* ************************************************************************** */
/*                                                                            */
/*                                                  if(success){};            */
/*   minishell.h                                    ██╗  ██╗██████╗           */
/*                                                  ██║  ██║╚════██╗          */
/*   By: atopalli | github/atrobp                   ███████║ █████╔╝          */
/*                                                  ╚════██║██╔═══╝           */
/*   Created: 2023/03/30 21:07:09 by atopalli            ██║███████╗          */
/*   Updated: 2023/04/04 10:15:46 by atopalli            ╚═╝╚══════╝.qc       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PROMPT "\033[1;37mm\033[1;32mi\033[1;37mni\033[1;32ms\033[1;37mhe\033[1;32mll\033[1;37m>\033[1;32m \033[0m"
# define PROMPT2 "\033[1;37mm\033[1;32mi\033[1;37mni\033[1;32ms\033[1;37mhe\033[1;32mll\033[0m"

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

typedef enum e_state
{
	EXIT,
	RUNNING,
}			t_state;
typedef struct s_env
{
	char	**envt;
	char	**path;
	int		size;
}			t_env;

typedef struct s_cmd
{
	char	**cmds;
	char	**args;
}			t_cmd;

typedef struct s_shell
{
	char	**cmds;
	char	**args;
	char	**path;
	char	*input;
	char	**envt;
	int		env_size;
	t_state	running;
}			t_shell;

// where we begin the shell

void		ft_startshell(t_shell *shell);
t_shell		*ft_initshell(char **envt);

// where we parse -- (parsing folder)

void		ft_parser(t_shell *shell);
int			ft_verifytokens(char **array);
int			ft_tokenize(t_shell *shell, char **array);
void		ft_create_cmds(t_shell *shell, char **array);

// where we deal with the input

char		**ft_split(char *s, char c);

// else

char		*ft_strdup(const char *s1);
int			ft_strlen(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strstr(const char *s1, const char *s2);
void		ft_free(t_shell *shell);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strccpy(char *dest, char *src, char c);
void		ft_sighandler(int sig);

// where we free the memory

void		ft_freeptr(char *ptr);
void		ft_freeptrptr(char **ptr);

#endif
