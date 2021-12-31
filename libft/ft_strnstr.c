/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:19:03 by sakllam           #+#    #+#             */
/*   Updated: 2021/11/07 19:49:03 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	k;

	i = 0;
	if (!big && !little)
		return (NULL);
	while (big[i] && len > (unsigned int) i)
	{
		k = 0;
		while (big[i + k] == little[k] && (unsigned int)i + k < len)
		{
			if (little[k + 1] == '\0')
				return ((char *)&big[i]);
			k++;
		}
		i++;
	}
	if (little[0] == '\0')
		return ((char *) &big[0]);
	return (0);
}
