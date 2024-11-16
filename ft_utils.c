/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:28:16 by nas91             #+#    #+#             */
/*   Updated: 2024/11/11 21:13:05 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_isgood(char c)
{
	if (c == WALL || c == SORTIE || c == COLL || c == POSD || c == VIDE
		|| c == PLAYER)
		return (0);
	return (1);
}

char	**ft_copymap(t_all *all)
{
	int		i;

	i = 0;
	all->copy = malloc(sizeof(char *) * (ft_countdouble(all->map) + 1));
	if (!all->copy)
		return (NULL);
	while (all->map[i])
	{
		all->copy[i] = ft_strdup(all->map[i]);
		if (!all->copy[i])
		{
			while (--i >= 0)
				free(all->copy[i]);
			free(all->copy);
			return (NULL);
		}
		i++;
	}
	all->copy[i] = NULL;
	return (all->copy);
}
