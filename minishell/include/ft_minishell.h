/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:41:32 by atopalli          #+#    #+#             */
/*   Updated: 2023/02/17 17:26:01 by anshimiy         ###   ########.fr       */
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
# define EMPTY ""
# define KGRN "\x1B[32m"
# define KNRM "\x1B[0m"

typedef struct s_list
{
	char	**env_vars;
	char	**local_vars;
	char	*cmd;
	char	*spec_cmd[4];
	int		cd_count;
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
void	ft_trim_input(t_list *p);
char	**ft_split(char *str, char set);

/*			ft_main.c				*/
void	ft_exit(t_list *list);
void	ft_valid_and_send(char **input, char **path);

/*			others					*/
void	ft_print_env(t_list *list);
char	**ft_split_set(char *str, char* set);
void    ft_edit_env(char* name, char* buffer, t_list *list);
size_t	ft_strlen(const char *s);
void	ft_free_str_array(char **array);

#endif
