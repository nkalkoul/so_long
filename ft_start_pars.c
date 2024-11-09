/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:00:53 by nkalkoul          #+#    #+#             */
/*   Updated: 2024/11/07 16:11:17 by nkalkoul         ###   ########.fr       */
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