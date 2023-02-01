/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:13:05 by atopalli          #+#    #+#             */
/*   Updated: 2022/09/27 13:04:42 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *source, char *dest, int *flag)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(ftstrlen(source) + ftstrlen(dest) + 1);
	if (str)
	{
		i = 0;
		j = 0;
		if (source)
		{
			while (source[j])
				str[i++] = source[j++];
			free(source);
		}
		while (*dest)
		{
			if (*dest == '\n')
				*flag = 1;
			str[i++] = *dest++;
		}
		str[i] = 0;
		return (str);
	}
	return (0);
}

char	*ft_retline(char *wholefile)
{
	char	*str;
	int		i;

	str = (char *)malloc(ftstrlen(wholefile) + 1);
	if (str)
	{
		i = 0;
		while (*wholefile)
		{
			str[i++] = *wholefile;
			if (*wholefile == '\n')
				break ;
			wholefile += 1;
		}
		str[i] = 0;
		return (str);
	}
	return (0);
}

char	*ft_restfile(char *file, int lastpos)
{
	char	*str;
	int		i;

	str = (char *)malloc((ftstrlen(file) - lastpos) + 1);
	if (str)
	{
		i = 0;
		if (file[lastpos])
		{
			while (file[lastpos])
			{
				str[i] = file[lastpos];
				i += 1;
				lastpos += 1;
			}
			free(file);
			str[i] = 0;
			return (str);
		}
		free(file);
		free(str);
	}
	return (0);
}

char	*ft_gnl(t_struct *gnl, int fd)
{
	static char	*str;

	gnl->flag = 0;
	gnl->buf = read(fd, gnl->temp, BUFFER_SIZE);
	while (gnl->buf > 0)
	{
		gnl->temp[gnl->buf] = 0;
		str = ft_strcpy(str, gnl->temp, &gnl->flag);
		if (gnl->flag == 0)
			gnl->buf = read(fd, gnl->temp, BUFFER_SIZE);
		else
			break ;
	}
	free(gnl->temp);
	if (str)
	{
		gnl->temp = ft_retline(str);
		str = ft_restfile(str, ftstrlen(gnl->temp));
		if (gnl->temp)
			return (gnl->temp);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	t_struct	gnl;

	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		gnl.temp = (char *)malloc(BUFFER_SIZE + 1);
		if (gnl.temp)
		{
			return (ft_gnl(&gnl, fd));
		}
	}
	return (0);
}
