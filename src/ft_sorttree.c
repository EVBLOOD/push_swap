/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorttree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 06:43:00 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/16 08:51:23 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_parttwo(int first, int next, int last, t_stack **a)
{
	if (first > next && next < last && last < first)
	{
		*a = ft_rotate(*a);
		ft_putstr_fd("ra\n", 1);
	}
	if (first < next && next > last && last > first)
	{
		ft_swap(*a);
		*a = ft_rotate(*a);
		ft_putstr_fd("sa\nra\n", 1);
	}
	if (first < next && next > last && last < first)
	{
		*a = ft_revrserotate(*a);
		ft_putstr_fd("rra\n", 1);
	}
}

void	ft_sorttree(t_stack	**a)
{
	int	first;
	int	next;
	int	last;

	last = (*a)->next->next->index;
	next = (*a)->next->index;
	first = (*a)->index;
	if (first > next && next < last && last > first)
	{
		ft_swap(*a);
		ft_putstr_fd("sa\n", 1);
	}
	if (first > next && next > last && last < first)
	{
		ft_swap(*a);
		*a = ft_revrserotate(*a);
		ft_putstr_fd("sa\nrra\n", 1);
	}
	ft_parttwo(first, next, last, a);
}
