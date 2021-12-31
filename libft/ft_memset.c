/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:55:51 by sakllam           #+#    #+#             */
/*   Updated: 2021/11/07 19:34:04 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int		i;
	char	*b;
	int		conv;

	i = 0;
	conv = n;
	b = NULL;
	if (conv > 0)
	{
		b = s;
		while (i < (int) n)
		{
			b[i] = (char) c;
			i++;
		}
	}
	return (s);
}
