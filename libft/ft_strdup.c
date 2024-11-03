/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 02:18:06 by nas91             #+#    #+#             */
/*   Updated: 2024/05/31 17:49:13 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	lens;

	lens = ft_strlen(s) + 1;
	new = malloc(sizeof(*s) * lens);
	if (new == NULL)
		return (NULL);
	new = (char *)ft_memcpy(new, s, lens);
	return (new);
}
