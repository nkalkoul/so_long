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

# define SIZE 64
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ECHAP 65307
# define WALL '1'
# define COLL 'C'
# define SORTIE 'E'
# define PLAYER 'P'
# define FLOOR '0'
# define IMGFLOOR "image/tatami.xpm"
# define IMGPLAYER "image/TYSON.xpm"
# define IMGWALL "image/PUNCHBOXE.xpm"
# define IMGCOL "image/GLOVES.xpm"
# define IMGSORT "image/ceinture.xpm"

typedef struct s_all
{
	char	*av1;
	char	**map;
	char	**copy;
	int		coll;
	int		sortie;
	int		player;
	int		cosortie;
	int		cocoll;
	int		x;
	int		y;
	int		lx;
	int		ly;
	int		ex;
	int		ey;
	void	*mlx;
	void	*imgcol;
	void	*imgsort;
	void	*imgplayer;
	void	*imgwall;
	void	*imgfloor;
	void	*winptr;
}	t_all;

int		ft_start_pars(t_all *all);
int		ft_check_rec(t_all	*all);
int		ft_check_mur(t_all *all);
int		ft_check_cara(t_all *all);
int		ft_isgood(char c);
int		ft_check_ber(char *str);
int		ft_check_content(t_all *all);
void	ft_check_count(char *str, t_all *all);
void	ft_display_maps(char **str);
char	**ft_copymap(t_all *all);
int		ft_fill(t_all *all);
int		ft_check_len(t_all *all);
void	ft_free_mlx(t_all *all);
void	ft_start_mlx(t_all *all);
void	ft_isexit(t_all *all);
void	ft_finish(t_all *all, int fin);
int		ft_touch(int keycode, t_all *all);
void	ft_value(t_all *all);

#endif
