/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:11:55 by nkalkoul          #+#    #+#             */
/*   Updated: 2024/05/31 18:57:25 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	cc = (char)c;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == cc)
			return ((char *)(s + i));
		i++;
	}
	if (cc == 0 && *(s + i) == 0)
		return (((char *)s + i));
	return (NULL);
}
