/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:25:10 by nkalkoul          #+#    #+#             */
/*   Updated: 2024/11/20 01:55:25 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_replace(t_all *all, int x, int y)
{
	static int	count = 0;

	if (all->map[y][x] != WALL)
	{
		ft_printf("count = %d\n", ++count);
		if (all->map[y][x] == COLL)
		{
			all->map[y][x] == FLOOR;
			all->coll--;
		}
		if (all->coll > 0 || all->map[y][x] != SORTIE)
		{
			mlx_put_image_to_window(all->mlx, all->winptr,
				all->imgplayer, x * SIZE, y * SIZE);
			mlx_put_image_to_window(all->mlx, all->winptr,
				all->imgfloor, all->x * SIZE, all->y * SIZE);
		}
		else
			(ft_printf("YOU WIN !\n"), ft_finish(all, 0));
		all->x = x;
		all->y = y;
	}
}

int	ft_touch(int keycode, t_all *all)
{
	if (keycode == ECHAP)
		ft_finish(all, 0);
	if (keycode == D_KEY)
		ft_replace(all, all->x + 1, all->y);
	if (keycode == A_KEY)
		ft_replace(all, all->x - 1, all->y);
	if (keycode == W_KEY)
		ft_replace(all, all->x, all->y - 1);
	if (keycode == S_KEY)
		ft_replace(all, all->x, all->y - 1);
	if (all->coll == 0)
		mlx_put_image_to_window(all->mlx, all->winptr,
			all->imgsort, all->ex * SIZE, all->ey * SIZE);
}
