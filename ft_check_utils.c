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
	int		j;

	j = 0;
	i = 0;
	str = all->map;
	all->coins = 0;
	all->player = 0;
	all->exit = 0;
	while (str[i])
	{
		ft_check_exit(str[i], all);
		ft_check_coin(str[i], all);
		ft_check_player(str[i], all);
		i++;
	}
	if (all->coins < 1)
		return (ft_putstr_fd("Error\nNo collectible", 2), 1);
	if (all->player != 1)
		return (ft_putstr_fd("Error\nNot or too many player", 2), 1);
	if (all->exit != 1)
		return (ft_putstr_fd("Error\nNot or too many exit", 2), 1);
	return (0);
}

void	ft_check_exit(char *str, t_all *all)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == EXIT)
			all->exit++;
		i++;
	}
}

void	ft_check_coin(char *str, t_all *all)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == COIN)
			all->coins++;
		i++;
	}
}

void	ft_check_player(char *str, t_all *all)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == PLAYER)
			all->player++;
		i++;
	}
}
