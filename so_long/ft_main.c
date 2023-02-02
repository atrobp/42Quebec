/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 23:19:58 by atopalli          #+#    #+#             */
/*   Updated: 2023/01/26 10:49:43 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_ischars(t_map *map, int pos)
{
	while (--pos >= 0)
	{
		if (map->map[pos] == 'E')
			map->end_pos += 1;
		if (map->map[pos] == 'P')
			map->start_pos += 1;
		if (map->map[pos] == 'C')
			map->items = 1;
		if (map->map[pos] == 'L' || map->map[pos] == 'R')
			map->start_pos = 2;
	}
	if (map->items && map->start_pos == 1 && map->end_pos == 1)
		return (1);
	write(1, "Error\nCheck your elements!\n", 27);
	return (0);
}

int	ft_ismap_valid(t_map *map)
{
	int	i;
	int	j;

	map->iswall = 0;
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			if (map->map[i * map->col + j] == '1')
			{
				if (i == 0 || i == map->row - 1)
					map->iswall += 1;
				if ((i < map->row && j == 0) || (j == map->col - 1))
					map->iswall += 1;
				if (i > 0 && i < map->row - 1 && j > 0 && j < map->col - 1)
					map->map[i * map->col + j] = '2';
			}
		}
	}
	if (map->iswall == map->col * 2 + map->row * 2)
		return (ft_ischars(map, map->col * map->row));
	printf("Error\nCheck em walls!\n");
	return (0);
}

int	ft_isfile_valid(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	if (s1[0] != 0)
	{
		while (s1[i] != 0)
		{
			j = 0;
			while (s2[j] == s1[i] && s2[j])
			{
				j += 1;
				i += 1;
			}
			if (s2[j] == 0)
				break ;
			i += 1;
		}
		return (s2[j] - s1[i] + 1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	if (argc == 2 && ft_isfile_valid(argv[1], ".ber") == 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
		{
			map.map = NULL;
			if (ft_gnl(fd, &map) > 0 && map.map)
			{
				if (ft_ismap_valid(&map) == 1)
					ft_start(&map, fd);
				free(map.map);
			}
			close(fd);
		}
		else
			printf("Error\nCouldn't open file!\n");
	}
	else
		write(1, "Error\nEither args or filename/extension!\n", 41);
	return (0);
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	write(1, &"0123456789"[n % 10], 1);
}
