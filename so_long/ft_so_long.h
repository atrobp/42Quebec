/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 23:23:37 by atopalli          #+#    #+#             */
/*   Updated: 2023/01/26 11:04:51 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx/mlx.h"

typedef struct s_map
{
	int	*map;
	int	col;
	int	row;
	int	index;
	int	start_pos;
	int	end_pos;
	int	items;
	int	iswall;
}		t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_x;
	int		img_y;
	char	elements[10];
	char	*elelemnts_str[10];
	int		mov_counter;
	t_map	*p;
}		t_mlx;

//gnl stuff
int		ft_gnl(int fd, t_map *map);
char	*ft_retstr(char *dst, char *src);
int		ft_filarray(t_map *map, char *str);
int		ft_strlen(char *str);

//game section
void	ft_start(t_map *map, int file_desc);
char	*ft_retimg(char c, t_mlx *mlx);
void	ft_putimgs(t_map *map, t_mlx *mlx);
int		ft_moving(int keycode, t_mlx *mlx);

//handling stuff
int		ft_close(t_mlx *mlx);
int		ft_keyhook(int keycode, t_mlx *mlx);
void	ft_imglink(t_mlx *mlx);
void	ft_putnbr(int n);

#endif
