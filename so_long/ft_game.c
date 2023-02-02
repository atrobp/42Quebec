/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:45:26 by atopalli          #+#    #+#             */
/*   Updated: 2023/01/26 10:34:04 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_find_elem(t_mlx *mlx, char el)
{
	int	x;
	int	y;
	int	temp;

	y = -1;
	temp = 0;
	while (++y < mlx->p->row)
	{
		x = -1;
		while (++x < mlx->p->col)
		{
			if (el == 'P')
			{
				if ((mlx->p->map[y * mlx->p->col + x] == 'P') || (mlx->p->map[y
							* mlx->p->col + x] == 'R') || (mlx->p->map[y
							* mlx->p->col + x] == 'L'))
					temp = y * mlx->p->col + x;
			}
			if (el == 'C' && (mlx->p->map[y * mlx->p->col + x] == 'C'))
				temp = y * mlx->p->col + x;
		}
	}
	return (temp);
}

int	ft_whats_there(char c, t_mlx *mlx)
{
	if (c == '1' || c == '2')
		return (0);
	if (c == 'E' && ft_find_elem(mlx, 'C') > 0)
		return (0);
	return (1);
}

char	ft_movement(int keycode)
{
	if (keycode == 13 || keycode == 2)
		return ('R');
	return ('L');
}

int	ft_moving(int keycode, t_mlx *mlx)
{
	int		pos;
	int		next_pos;
	char	prev_el;

	next_pos = 0;
	pos = ft_find_elem(mlx, 'P');
	if (keycode == 13)
		next_pos = pos - mlx->p->col;
	else if (keycode == 0)
		next_pos = pos - 1;
	else if (keycode == 1)
		next_pos = pos + mlx->p->col;
	else if (keycode == 2)
		next_pos = pos + 1;
	if (ft_whats_there(mlx->p->map[next_pos], mlx) == 1)
	{
		prev_el = mlx->p->map[next_pos];
		if ((prev_el == 'X') || (prev_el == 'E' && ft_find_elem(mlx, 'C') == 0))
			ft_close(mlx);
		mlx->p->map[next_pos] = ft_movement(keycode);
		mlx->p->map[pos] = '0';
	}
	return (ft_whats_there(mlx->p->map[next_pos], mlx));
}

void	ft_start(t_map *map, int fd)
{
	t_mlx	mlx;
	int		x;
	int		y;

	close(fd);
	x = map->col * 32;
	y = map->row * 32;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, x, y, "./so_long");
	mlx.p = map;
	mlx.mov_counter = 0;
	ft_imglink(&mlx);
	ft_putimgs(mlx.p, &mlx);
	mlx_hook(mlx.win, 17, 1L << 0, ft_close, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, ft_keyhook, &mlx);
	mlx_loop(mlx.mlx);
}
