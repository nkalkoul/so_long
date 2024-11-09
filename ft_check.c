/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:00:53 by nkalkoul          #+#    #+#             */
/*   Updated: 2024/11/09 18:34:33 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_start_pars(t_all *all)
{
	if (ft_check_rec(all) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_mur(all) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_cara(all) == EXIT_FAILURE)
		return (EXIT_FAILURE);
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
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_mur(t_all *all)
{
	int		i;
	int		j;
	char	**str;

	str = all->map;
	i = 0;
	j = 0;
	while (str[i][j++])
	{
		if (str[i][j] != WALL)
			return (EXIT_FAILURE);
	}
	while (str[i++])
	{
		if (str[i][0] != WALL || str[i][ft_strlen(str[i]) - 1] != WALL)
			return (EXIT_FAILURE);
	}
	j= 0;
	while (str[i - 1][j++])
	{
		if (str[i][j] != WALL)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_isgood(int c)
{
	if ( c == WALL || c == EXIT || c == COIN || c == POSD || c == VIDE)
		return (0);
	return (1);
}
int	ft_check_cara(t_all *all)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	while (str[i++])
	{
		j = 0;
		while (str[i][j++])
		{
			if (ft_isgood(str[i][j] == 1))
				return (EXIT_FAILURE);
		}
	}
}
