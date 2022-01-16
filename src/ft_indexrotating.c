/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexrotating.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 06:51:44 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/16 08:45:44 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_theend(t_stack **a, int counting)
{
	if (counting != ft_optimize(counting, ft_stacksize(*a)))
	{
		counting = ft_optimize(counting, ft_stacksize(*a));
		while (counting)
		{
			*a = ft_revrserotate(*a);
			ft_putstr_fd("rra\n", 1);
			counting--;
		}
	}
	else
	{
		while (counting)
		{
			*a = ft_rotate(*a);
			ft_putstr_fd("ra\n", 1);
			counting--;
		}
	}
}

void	ft_markingtwo(t_stack *data, t_stack *temp, int *number, int tmp)
{
	while (data)
	{
		if (tmp <= data->index)
		{
			tmp = data->index;
			data->push = 0;
		}
		else
			data->push = 1;
		data = data->next;
	}
	data = temp;
	while (data && data->index != *number)
	{
		if (tmp <= data->index)
		{
			tmp = data->index;
				data->push = 0;
		}
		else
			data->push = 1;
		data = data->next;
	}
}
