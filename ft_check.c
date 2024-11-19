/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:00:53 by nkalkoul          #+#    #+#             */
/*   Updated: 2024/11/11 21:29:32 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_start_pars(t_all *all)
{
	if (ft_check_rec(all) == 1)
		return (ft_putstr_fd("Error\nThe map is not a rectangle\n", 2),
			1);
	if (ft_check_mur(all) == 1)
		return (ft_putstr_fd("Error\nThe map is not surrounded by a wall\n", 2),
			1);
	if (ft_check_len(all) == 1)
		return (ft_putstr_fd("Error\nTo smaaaaall", 2), 1);
	if (ft_check_cara(all) == 1)
		return (ft_putstr_fd
			("Error\nThere is one or more invalid characters in the map\n", 2),
			1);
	if (ft_check_content(all) == 1)
		return (1);
	return (0);
}

int	ft_check_rec(t_all	*all)
{
	int		i;
	char	**str;

	str = all->map;
	i = 0;
	while (str[i + 1])
	{
		if (ft_strlen(str[i]) != ft_strlen(str[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_mur(t_all *all)
{
	int		i;
	int		j;
	char	**str;

	str = all->map;
	i = 0;
	j = 0;
	while (str[i][j])
	{
		if (str[i][j++] != WALL)
			return (1);
	}
	while (str[i])
	{
		if (str[i][0] != WALL || str[i][ft_strlen(str[i]) - 1] != WALL)
			return (1);
		i++;
	}
	j = 0;
	while (str[i - 1][j])
	{
		if (str[i - 1][j++] != WALL)
			return (1);
	}
	return (0);
}

int	ft_check_cara(t_all *all)
{
	int		i;
	int		j;
	char	**str;

	str = all->map;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_isgood(str[i][j]) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_ber(char *str)
{
	int		i;
	char	*pt;

	i = 0;
	pt = ft_strchr(str, '.');
	if (pt == NULL)
		return (1);
	while (ft_strchr(pt + 1, '.'))
		pt = ft_strchr(pt + 1, '.');
	if (ft_strncmp(pt, ".ber", 4) != 0)
		return (1);
	else
		return (0);
}
