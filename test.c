/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:17:03 by nkalkoul          #+#    #+#             */
/*   Updated: 2024/11/07 16:22:18 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void ft_display_maps(char **res)
{
	int i = 0;

	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
	return ;
}
char	*ft_createmap(t_all *all)
{
	int		fd;
	char	*line;
	char	*res;


	fd = open(all->av1,O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nFAILD OPEN", 2), NULL);
	res = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
			return (free(line), free(res), NULL);
		res = ft_re_strjoin(res, line);
		if (!res)
			return (free(line), NULL);
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), res);
}

char	**ft_get_map(t_all *all)
{
	char	**map;
	map = ft_split(ft_createmap(all), '\n');
	if (!map)
		return (NULL);
	return (map);
}

int	fill_data(char **av, t_all *all)
{
	all -> av1 = av[1];
	//secu chemin ;
	all -> map = ft_get_map(all);
	if (all->map == NULL)
		return (EXIT_FAILURE);
	ft_display_maps(all->map);
	all -> coin = 0;
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_all	all;

	if (fill_data(av, &all) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// if (ft_start_pars(&all) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);				
}

