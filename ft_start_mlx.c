/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 03:01:02 by nas91             #+#    #+#             */
/*   Updated: 2024/11/19 23:05:07 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_if(char s, t_all *all, int x, int y)
{
	if (s == WALL)
		mlx_put_image_to_window
			(all->mlx, all->winptr, all->imgwall, x * SIZE, y * SIZE);
	if (s == COLL)
		mlx_put_image_to_window
		(all->mlx, all->winptr, all->imgcol, x * SIZE, y * SIZE);
	if (s == PLAYER)
		mlx_put_image_to_window
			(all->mlx, all->winptr, all->imgplayer, x * SIZE, y * SIZE);
	if (s == FLOOR || s == SORTIE)
		mlx_put_image_to_window
			(all->mlx, all->winptr, all->imgfloor, x * SIZE, y * SIZE);
}

void	ft_fill_window(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	ft_display_maps(all->map);
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			ft_if(all->map[i][j], all, j, i);
			j++;
		}
		i++;
	}
}

int	ft_init_image(t_all *all)
{
	int	wimg;
	int	himg;

	all->imgfloor = mlx_xpm_file_to_image(all->mlx, IMGFLOOR, &wimg, &himg);
	if (!all->imgfloor || wimg != SIZE || himg != SIZE)
		return (ft_free_mlx(all), 1);
	all->imgplayer = mlx_xpm_file_to_image(all->mlx, IMGPLAYER, &wimg, &himg);
	if (!all->imgplayer || wimg != SIZE || himg != SIZE)
		return (ft_free_mlx(all), 1);
	all->imgwall = mlx_xpm_file_to_image(all->mlx, IMGWALL, &wimg, &himg);
	if (!all->imgwall || wimg != SIZE || himg != SIZE)
		return (ft_free_mlx(all), 1);
	all->imgcol = mlx_xpm_file_to_image(all->mlx, IMGCOL, &wimg, &himg);
	if (!all->imgcol || wimg != SIZE || himg != SIZE)
		return (ft_free_mlx(all), 1);
	return (0);
}

int	ft_start_mlx(t_all *all)
{
	int	x;
	int	y;

	all->mlx = mlx_init();
	if (!all->mlx)
		return (ft_putstr_fd("Error\nError mlx\n", 2), 1);
	mlx_get_screen_size(all->mlx, &x, &y);
	if (all->lx * SIZE > x || all->ly * SIZE > y)
		return (ft_putstr_fd("Error\nMap size is too large\n", 2), 1);
	all->winptr = mlx_new_window
		(all->mlx, all->lx * SIZE, all->ly * SIZE, "nassolong");
	if (!all->winptr)
		return (mlx_destroy_display(all->mlx),
			ft_putstr_fd("Error\nError mlx windows", 2), 1);
	if (ft_init_image(all) == 1)
	{
		mlx_destroy_display(all->mlx);
		return (ft_putstr_fd("Error\nError with image loading\n", 2), 1);
	}
	ft_fill_window(all);
	mlx_loop(all->mlx);
	return (0);
}
