/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:42:33 by nkalkoul          #+#    #+#             */
/*   Updated: 2024/11/11 23:17:52 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(t_all *all, int y, int x)
{
	if (all->copy[y][x] == WALL || all->copy[y][x] == 'N')
		return ;
	if (all->copy[y][x] == COLL)
		all->cocoll--;
	if (all->copy[y][x] == SORTIE)
		all->cosortie--;
	all->copy[y][x] = 'N';
	ft_flood_fill(all, y, x + 1);
	ft_flood_fill(all, y, x - 1);
	ft_flood_fill(all, y + 1, x);
	ft_flood_fill(all, y - 1, x);
}

int	ft_fill(t_all *all)
{
	all->y = 0;
	all->cocoll = all->coll;
	all->cosortie = all->sortie;
	ft_copymap(all);
	while (all->map[all->y])
	{
		all->x = 0;
		while (all->map[all->y][all->x])
		{
			if (all->map[all->y][all->x] == PLAYER)
				break ;
			all->x++;
		}
		if (all->map[all->y][all->x] == PLAYER)
			break ;
		all->y++;
	}
	ft_flood_fill(all, all->y, all->x);
	ft_free_double(all->copy);
	if (all->cocoll != 0 || all->cosortie != 0)
		return (ft_putstr_fd("Error\nInvalid path\n", 2), 1);
	return (0);
}
