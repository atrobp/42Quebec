/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:01:51 by atopalli          #+#    #+#             */
/*   Updated: 2022/12/28 13:18:29 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_freeall(char **array, int fd)
{
	free(array[0]);
	free(array[1]);
	free(array[2]);
	free(array);
	close(fd);
}

int	main(int argc, char *argv[])
{
	char	**myarray;
	pid_t	cpid;
	int		fd;
	int		isdoc;

	if (ft_validate_all(argc, argv, 0) == 1)
	{
		fd = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (ft_validate_all(fd, 0, 1) == 1)
		{
			myarray = ft_create_array(argc);
			isdoc = ft_copy_cmp(argv[1], "here_doc", 'k');
			if (myarray)
			{
				ft_cmdtocopy(argv + 1 + isdoc, myarray[2], isdoc);
				cpid = fork();
				ft_sendcommand(myarray, cpid, fd);
			}
			ft_freeall(myarray, fd);
		}
	}
	return (0);
}

int	ft_copy_cmp(char *s1, char *s2, char todo)
{
	int	i;

	i = 0;
	if (todo == 'k')
	{
		while (s1[i] == s2[i] && s1[i] && s1[i])
			i += 1;
		if (s2[i] == s1[i])
			return (1);
	}
	else
	{
		while (s1[i])
		{
			s2[i] = s1[i];
			i += 1;
		}
		s2[i] = 0;
		return (i);
	}
	return (0);
}

char	**ft_create_array(int size)
{
	int		i;
	int		mallocsize[3];
	char	*copyfrom[3];
	char	**array;

	mallocsize[0] = 10;
	mallocsize[1] = 3;
	mallocsize[2] = size * 10;
	copyfrom[0] = "/bin/bash";
	copyfrom[1] = "-c";
	copyfrom[2] = "cmd";
	i = 0;
	array = malloc(sizeof(array) * size);
	if (array)
	{
		while (i <= 2)
		{
			array[i] = malloc(sizeof(char) * mallocsize[i]);
			ft_copy_cmp(copyfrom[i], array[i], 0);
			i += 1;
		}
		array[3] = 0;
		return (array);
	}
	return (0);
}

int	ft_validate_all(int ac, char **av, char checkfd)
{
	int	i;

	i = 0;
	if (checkfd > 0 && ac >= 0)
		return (1);
	else if (ac >= 5)
	{
		while (av[i] && i < ac)
			i += 1;
		if (av[i] || i == ac)
			return (1);
	}
	printf("Something somewhere went wrong!\n");
	return (0);
}
