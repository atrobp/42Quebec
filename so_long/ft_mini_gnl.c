/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minignl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:51:43 by atopalli          #+#    #+#             */
/*   Updated: 2022/12/25 15:32:21 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_gnl(int fd, t_map *map)
{
	char	*final;
	char	*temp;

	temp = malloc(sizeof(char) * 2);
	if (temp)
	{
		final = NULL;
		map->index = 0;
		map->row = 0;
		while (read(fd, temp, 1) > 0 && ++map->index && map->index > 0)
		{
			temp[1] = 0;
			final = ft_retstr(final, temp);
			if (map->row == 0 && temp[0] <= '\n')
			{
				map->col = map->index - 1;
				map->map = malloc(sizeof(int) * map->col * map->col);
			}
			if (temp[0] <= '\n')
				map->index = ft_filarray(map, final);
		}
		free(final);
		free(temp);
	}
	return (map->index);
}

char	*ft_retstr(char *dst, char *src)
{
	char		*temp;
	int			i;
	int			j;
	static int	time = 1;

	temp = malloc(sizeof(char) * (ft_strlen(src) * time) + 1);
	if (temp)
	{
		i = 0;
		j = -1;
		if (time > 1)
		{
			while (dst[++j])
				temp[i++] = dst[j];
			free(dst);
			j = -1;
		}
		while (src[++j] && src[j] != '\n')
			temp[i++] = src[j];
		temp[i] = 0;
		time += 1;
		return (temp);
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i += 1;
	}
	return (i);
}

int	ft_filarray(t_map *map, char *str)
{
	int	i;

	i = -1;
	if (ft_strlen(str) == map->col)
	{
		while (str[++i])
		{
			map->map[map->row * map->col + i] = str[i];
		}
		map->row += 1;
		str[0] = 0;
	}
	else
		write(1, "Error\nIncorrect map size!\n", 26);
	return (i);
}
