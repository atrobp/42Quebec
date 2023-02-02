/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:26:07 by atopalli          #+#    #+#             */
/*   Updated: 2022/12/28 13:17:37 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>

//func in ft_main
void	ft_freeall(char **array, int fd);
int		ft_copy_cmp(char *s1, char *s2, char todo);
char	**ft_create_array(int size);
int		ft_validate_all(int ac, char **av, char checkfd);

//func in ft_pipex
void	ft_cmdtocopy(char **argv, char *command, int isdoc);
void	ft_heredoc(char **argv, char *command);
void	ft_sendcommand(char **array, int childpid, int fd);

#endif
