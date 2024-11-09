/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:29:48 by nas91             #+#    #+#             */
/*   Updated: 2024/11/09 16:05:50 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# define WALL 1
# define COIN 'C'
# define EXIT 'E'
# define POSD 'P'
# define VIDE '0'

typedef struct s_all
{
	char	*av1;
	char	**map;
	int		coin;
}	t_all;

void	ft_free_map(t_all *all);

#endif 
