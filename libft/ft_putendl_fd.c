/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:58:36 by sakllam           #+#    #+#             */
/*   Updated: 2021/11/07 19:57:39 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	nl;
	int		ln;

	nl = '\n';
	if (!s)
		return ;
	ln = ft_strlen(s);
	write(fd, s, ln);
	write(fd, &nl, 1);
}
