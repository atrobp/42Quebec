/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:41:32 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/09 19:36:57 by atopalli         ###   ########.fr       */
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

# define END 0
# define VAR
# define VALUE
# define EMPTY ""
# define KGRN "\x1B[32m"
# define KNRM "\x1B[0m"

typedef struct s_list
{
	char	**env_vars;
	char	**local_vars;
	char	*cmd;
	char	*spec_cmd[4];
	size_t	len;
}		t_list;

/*			ft_mem_funcs			*/
void	*ft_memcopy(void *s1, void *s2, size_t n, unsigned char stopat);
size_t	ft_memlen(void *s1, unsigned char stopat);
void	*ft_memdup(void *ptr, void *ptr2, char stopat);
int		ft_memcmp(void *s1, void *s2);
bool	ft_memchr(void *ptr, unsigned char needle);

/*			ft_env_funcs			*/
t_list	ft_env_import(char **env);
void	ft_env_edit_add(t_list *s);
void	ft_env_delete(t_list *s);
void	ft_env_print(t_list *s);
char	*ft_getenv(char *name, char **env);

/*			ft_allocation_funcs		*/
void	*ft_calloc(size_t nitems, size_t size);
void	*ft_realloc(void *ptr, size_t size);

/*			ft_command_funcs		*/
void	*ft_trimcmd(char *str);
void	ft_check_cmd(t_list *p);
void	ft_setspecial_cmd(t_list *p);

void	ft_exit(t_list *list);

#endif
