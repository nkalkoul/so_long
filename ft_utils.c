/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nas91 <kalkoul.nassim@gmail.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-08 12:28:16 by nas91             #+#    #+#             */
/*   Updated: 2024-11-08 12:28:16 by nas91            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_all *all)
{
	int		i;

	i = 0;
	while (all->map[i] != NULL)
	{
		free(all->map[i]);
		i++;
	}
	free(all->map);
	all->map = NULL;
}

int	ft_isgood(char c)
{
	if (c == WALL || c == EXIT || c == COIN || c == POSD || c == VIDE)
		return (0);
	return (1);
}