/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:13:31 by nkalkoul          #+#    #+#             */
/*   Updated: 2024/11/11 22:38:06 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_content(t_all *all)
{
	char	**str;
	int		i;

	i = 0;
	str = all->map;
	all->coll = 0;
	all->player = 0;
	all->sortie = 0;
	while (str[i])
	{
		ft_check_count(str[i], all);
		i++;
	}
	if (all->coll < 1)
		return (ft_putstr_fd("Error\nNo collectible", 2), 1);
	if (all->player != 1)
		return (ft_putstr_fd("Error\nWrong number of player", 2), 1);
	if (all->sortie != 1)
		return (ft_putstr_fd("Error\nWrong number of sortie", 2), 1);
	return (0);
}

void	ft_check_count(char *str, t_all *all)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == SORTIE)
			all->sortie++;
		if (str[i] == COLL)
			all->coll++;
		if (str[i] == PLAYER)
			all->player++;
		i++;
	}
}

int	ft_check_len(t_all *all)
{
	all->lx = ft_strlen(all->map[0]);
	all->ly = ft_countdouble(all->map);
	if (all->lx < 3 || all->ly < 3)
		return (1);
	if (all->lx == 3)
	{
		if (all->ly < 5)
			return (1);
	}
	if (all->ly >= 3)
	{
		if (all->lx < 5)
			return (1);
	}
	return (0);
}
