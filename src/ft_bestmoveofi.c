/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bestmoveofi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:49:51 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/19 21:09:46 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_bestmovesindex(t_stack *a, t_stack *b, int index, int correntb)
{
	int		perfect;
	t_best	cora_index;
	t_stack	*tmpa;
	t_stack	*tmpb;

	perfect = ft_stacksize(a) + ft_stacksize(b);
	correntb = 0;
	tmpb = b;
	tmpa = a;
	index = b->index;
	while (b)
	{
		cora_index.a = ft_movementsfuture(a, b->index);
		cora_index.b = b->index;
		if (perfect > ft_co(cora_index, tmpa, tmpb, correntb))
		{
			index = b->index;
			perfect = ft_co(cora_index, tmpa, tmpb, correntb);
		}
		b = b->next;
		correntb++;
		a = tmpa;
	}
	b = tmpb;
	return (index);
}
