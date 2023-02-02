/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:12:08 by atopalli          #+#    #+#             */
/*   Updated: 2022/12/28 13:18:49 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_heredoc(char **argv, char *command)
{
	int	index;
	int	i;

	i = 0;
	index = 1;
	i += ft_copy_cmp(argv[1], command, 0);
	i += ft_copy_cmp(" << ", command + i, 0);
	i += ft_copy_cmp(argv[0], command + i, 0);
	while (argv[++index])
	{
		i += ft_copy_cmp(argv[index], command + i, 0);
		if (index == 0)
			i += ft_copy_cmp(" ", command + i, 0);
		else if (!argv[index + 2])
			i += ft_copy_cmp(" >> ", command + i, 0);
		else if (argv[index + 1] && index > 0)
			i += ft_copy_cmp(" | ", command + i, 0);
	}
}

void	ft_cmdtocopy(char **argv, char *command, int isdoc)
{
	int	index;
	int	i;

	i = 0;
	index = -1;
	if (isdoc == 1)
		ft_heredoc(argv, command);
	else
	{
		i += ft_copy_cmp("< ", command + i, 0);
		while (argv[++index])
		{
			i += ft_copy_cmp(argv[index], command + i, 0);
			if (index == 0)
				i += ft_copy_cmp(" ", command + i, 0);
			else if (!argv[index + 2])
				i += ft_copy_cmp(" > ", command + i, 0);
			else if (argv[index + 1] && index > 0)
				i += ft_copy_cmp(" | ", command + i, 0);
		}
	}
}

void	ft_sendcommand(char **array, int childpid, int fd)
{
	int	status;

	if (childpid == 0)
	{
		dup2(fd, 1);
		execve(array[0], array, 0);
	}
	else
		waitpid(childpid, &status, 0);
}
