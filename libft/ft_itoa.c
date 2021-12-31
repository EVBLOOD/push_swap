/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:49:12 by sakllam           #+#    #+#             */
/*   Updated: 2021/11/04 17:04:07 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counting(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = n * -1;
	if (n > 9)
		i = ft_counting(n / 10);
	i++;
	return (i);
}

static void	ft_writing(char *p, long int n, int *i)
{
	if (n < 0)
		n = n * -1;
	if (n <= 9)
	{
		p[*i] = '0' + n;
		(*i)++;
	}
	else
	{
		ft_writing(p, n / 10, i);
		ft_writing(p, n % 10, i);
	}
}

char	*ft_itoa(int n)
{
	char	*p;
	int		count;

	count = ft_counting(n);
	if (n < 0)
		count += 1;
	p = (char *) malloc((count + 1) * sizeof(char));
	if (!p)
		return (NULL);
	count = 0;
	if (n < 0)
	{
		count = 1;
		p[0] = '-';
		ft_writing(p, n, &count);
	}
	else
		ft_writing(p, n, &count);
	p[count] = '\0';
	return (p);
}
