/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:51:06 by sakllam           #+#    #+#             */
/*   Updated: 2021/11/08 16:10:06 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	int				i;

	if (!n)
		return (NULL);
	src = (unsigned char *) s;
	i = 0;
	while (n > 0)
	{
		if (src[i] == (unsigned char)c)
			return ((void *) &s[i]);
		i++;
		n--;
	}
	if (c == '\0')
		return ((void *) &s[ft_strlen(s)]);
	return (NULL);
}
