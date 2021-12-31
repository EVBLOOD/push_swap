/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:57:02 by sakllam           #+#    #+#             */
/*   Updated: 2021/11/08 16:14:28 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s + start) < len)
		p = (char *) malloc((ft_strlen(s + start) + 1) * sizeof(char));
	else
		p = (char *) malloc(((int) len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (i < (int) len && s[i + start] && !(start >= ft_strlen(s)))
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}
