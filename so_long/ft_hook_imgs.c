/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:24:47 by atopalli          #+#    #+#             */
/*   Updated: 2023/01/21 14:14:49 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx->p->map);
	exit(0);
}

int	ft_keyhook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		ft_close(mlx);
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		if (ft_moving(keycode, mlx) == 1)
		{
			write(1, "movement counter: ", 18);
			mlx->mov_counter += 1;
			ft_putnbr(mlx->mov_counter);
			write(1, "\n", 1);
			ft_putimgs(mlx->p, mlx);
		}
	}
	return (0);
}

char	*ft_retimg(char c, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (c == mlx->elements[i])
			break ;
		i += 1;
	}
	return (mlx->elelemnts_str[i]);
}

void	ft_putimgs(t_map *map, t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			mlx->img = mlx_xpm_file_to_image(mlx->mlx, ft_retimg
					(map->map[y * map->col + x], mlx),
					&mlx->img_x, &mlx->img_y);
			mlx_put_image_to_window(mlx->mlx,
				mlx->win, mlx->img, 32 * x, 32 * y);
			mlx_destroy_image(mlx->mlx, mlx->img);
			x += 1;
		}
		y += 1;
	}
}

void	ft_imglink(t_mlx *mlx)
{
	mlx->elements[0] = '0';
	mlx->elements[1] = '1';
	mlx->elements[2] = 'C';
	mlx->elements[3] = 'P';
	mlx->elements[4] = 'E';
	mlx->elements[5] = '2';
	mlx->elements[6] = 'R';
	mlx->elements[7] = 'L';
	mlx->elements[8] = 'X';
	mlx->elelemnts_str[0] = "./imgs/tile.xpm";
	mlx->elelemnts_str[1] = "./imgs/border.xpm";
	mlx->elelemnts_str[2] = "./imgs/beer.xpm";
	mlx->elelemnts_str[3] = "./imgs/cowboy.xpm";
	mlx->elelemnts_str[4] = "./imgs/exit.xpm";
	mlx->elelemnts_str[5] = "./imgs/crate.xpm";
	mlx->elelemnts_str[6] = "./imgs/walkright.xpm";
	mlx->elelemnts_str[7] = "./imgs/walkleft.xpm";
	mlx->elelemnts_str[8] = "./imgs/enemies.xpm";
}
