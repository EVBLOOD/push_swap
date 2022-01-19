/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:50:11 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/19 22:50:50 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap.h"
#include "get_next_line/get_next_line.h"

int	rest_cond(const char *line, t_stack **a, t_stack **b)
{
	int	size;

	size = ft_strlen(line);
	if (!ft_strncmp(line, "rrr\n", size))
	{
		*a = ft_revrserotate(*a);
		*b = ft_revrserotate(*b);
	}
	else
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (1);
}
