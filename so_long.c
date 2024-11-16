/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:17:03 by nkalkoul          #+#    #+#             */
/*   Updated: 2024/11/11 21:34:47 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	ft_display_maps(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	return ;
}

char	*ft_createmap(t_all *all)
{
	int		fd;
	char	*line;
	char	*res;

	fd = open(all->av1, O_RDONLY);
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
	return (res);
}

char	**ft_get_map(t_all *all)
{
	char	**map;
	char	*res;

	res = ft_createmap(all);
	if (!res)
		return (ft_putstr_fd("Error\nEMPTY FUCKING LINE", 2), NULL);
	map = ft_split(res, '\n');
	if (!map)
		return (free(res), NULL);
	return (free(res), map);
}

int	fill_data(char **av, t_all *all)
{
	all -> av1 = av[1];
	if (ft_check_ber(all->av1) == 1)
		return (ft_putstr_fd
			("the file is not in the correct format", 2),
			1);
	all -> map = ft_get_map(all);
	if (all->map == NULL)
		return (1);
	//ft_display_maps(all->map);
	return (0);
}

int	main(int ac, char **av)
{
	t_all	all;

	if (ac == 2)
	{
		if (fill_data(av, &all) == 1)
			return (1);
		if (ft_start_pars(&all) == 1)
			return (ft_free_double(all.map), 1);
		if (ft_fill(&all) == 1)
			return (ft_free_double(all.map), 1);
		return (ft_free_double(all.map), 0);
	}
	return (ft_putstr_fd("Error\nWrong number of args", 2), 0);
}
