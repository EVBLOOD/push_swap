/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:59:39 by sakllam           #+#    #+#             */
/*   Updated: 2021/11/04 19:02:03 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long nb, int fd)
{
	char	c;

	if (nb < 0)
	{
		c = '-';
		nb = nb * -1;
		write(fd, &c, 1);
	}
	if (nb <= 9)
	{
		c = nb + '0';
		write (fd, &c, 1);
	}
	else
	{
		ft_putnbr(nb / 10, fd);
		ft_putnbr(nb % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
