/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:29:48 by nas91             #+#    #+#             */
/*   Updated: 2024/11/11 21:47:50 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# define WALL '1'
# define COIN 'C'
# define EXIT 'E'
# define POSD 'P'
# define VIDE '0'
# define PLAYER 'P'

typedef struct s_all
{
	char	*av1;
	char	**map;
	int		coins;
	int		exit;
	int		player;
}	t_all;

void	ft_free_map(t_all *all);
int		ft_start_pars(t_all *all);
int		ft_check_rec(t_all	*all);
int		ft_check_mur(t_all *all);
int		ft_check_cara(t_all *all);
int		ft_isgood(char c);
int		ft_check_ber(char *str);
int		ft_check_content(t_all *all);
void	ft_check_exit(char *str, t_all *all);
void	ft_check_coin(char *str, t_all *all);
void	ft_check_player(char *str, t_all *all);

#endif 
