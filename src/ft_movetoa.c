/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movetoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 06:47:35 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/16 08:46:28 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_getthecount(t_stack *b, int index)
{
	t_stack	*tmp;
	int		i;

	tmp = b;
	i = 0;
	while (b)
	{
		if (b->index == index)
			break ;
		i++;
		b = b->next;
	}
	b = tmp;
	return (i);
}

void	ft_bothr(t_stack **a, t_stack **b, int amoves, int bmoves)
{
	while (amoves && bmoves)
	{
		*a = ft_revrserotate(*a);
		*b = ft_revrserotate(*b);
		ft_putstr_fd("rrr\n", 1);
		amoves--;
		bmoves--;
	}
	while (amoves)
	{
		*a = ft_revrserotate(*a);
		ft_putstr_fd("rra\n", 1);
		amoves--;
	}
	while (bmoves)
	{
		*b = ft_revrserotate(*b);
		ft_putstr_fd("rrb\n", 1);
		bmoves--;
	}
	ft_push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	ft_bisn_aisr(t_stack **a, t_stack **b, int amoves, int bmoves)
{
	while (amoves)
	{
		*a = ft_revrserotate(*a);
		ft_putstr_fd("rra\n", 1);
		amoves--;
	}
	while (bmoves)
	{
		*b = ft_rotate(*b);
		ft_putstr_fd("rb\n", 1);
		bmoves--;
	}
	ft_push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	ft_bothn(t_stack **a, t_stack **b, int amoves, int bmoves)
{
	while (amoves && bmoves)
	{
		*a = ft_rotate(*a);
		*b = ft_rotate(*b);
		ft_putstr_fd("rr\n", 1);
		amoves--;
		bmoves--;
	}
	while (amoves)
	{
		*a = ft_rotate(*a);
		ft_putstr_fd("ra\n", 1);
		amoves--;
	}
	while (bmoves)
	{
		*b = ft_rotate(*b);
		ft_putstr_fd("rb\n", 1);
		bmoves--;
	}
	ft_push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	ft_bisr_aisn(t_stack **a, t_stack **b, int amoves, int bmoves)
{
	while (amoves)
	{
		*a = ft_rotate(*a);
		ft_putstr_fd("ra\n", 1);
		amoves--;
	}
	while (bmoves)
	{
		*b = ft_revrserotate(*b);
		ft_putstr_fd("rrb\n", 1);
		bmoves--;
	}
	ft_push(b, a);
	ft_putstr_fd("pa\n", 1);
}
