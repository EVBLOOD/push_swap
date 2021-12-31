/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:52:54 by sakllam           #+#    #+#             */
/*   Updated: 2021/11/07 19:45:23 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			i;
	char		*x;
	const char	*y;

	if (!src && !dest)
		return (NULL);
	x = dest;
	y = src;
	i = 0;
	while ((size_t) i < n)
	{
		x[i] = y[i];
		i++;
	}
	return (dest);
}
