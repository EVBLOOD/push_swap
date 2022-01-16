/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_utils_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 06:39:55 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/16 08:52:35 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_pushing(t_stack *a)
{
	int		count;
	t_stack	*tmp;

	tmp = a;
	count = 0;
	while (tmp)
	{
		if (tmp->push)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void	ft_pushtob(t_stack **a, t_stack **b)
{
	int		count;
	t_stack	*temp;

	temp = *a;
	count = 0;
	while (ft_pushing(*a) && ft_stacksize(*a) > 3)
	{
		if ((*a)->push)
		{
			ft_push(a, b);
			ft_putstr_fd("pb\n", 1);
		}
		else
		{
			*a = ft_rotate(*a);
			ft_putstr_fd("ra\n", 1);
		}
	}
}

int	ft_bestmovesindex(t_stack *a, t_stack *b, int index, int correntb)
{
	int		perfect;
	int		corrent;
	t_stack	*tmpa;
	t_stack	*tmpb;

	perfect = ft_stacksize(a) + ft_stacksize(b);
	correntb = 0;
	tmpb = b;
	tmpa = a;
	index = b->index;
	while (b)
	{
		corrent = ft_optimize(ft_movementsfuture(a, b->index),
				ft_stacksize(tmpa));
		if (perfect > ft_optimize(correntb, ft_stacksize(tmpb)) + corrent)
		{
			index = b->index;
			perfect = ft_optimize(correntb, ft_stacksize(tmpb)) + corrent;
		}
		b = b->next;
		correntb++;
		a = tmpa;
	}
	b = tmpb;
	return (index);
}

void	ft_moveittoa(t_stack **a, t_stack **b, int index, int toa)
{
	int		tob;
	t_stack	*tmp;
	t_stack	*tmpa;

	tmp = *b;
	tmpa = *a;
	tob = ft_getthecount(*b, index);
	toa = ft_movementsfuture(*a, index);
	if (tob != ft_optimize(tob, ft_stacksize(*b))
		&& toa != ft_optimize(toa, ft_stacksize(*a)))
		ft_bothr(a, b, ft_optimize(toa, ft_stacksize(*a)),
			ft_optimize(tob, ft_stacksize(*b)));
	else if (tob == ft_optimize(tob, ft_stacksize(*b))
		&& toa != ft_optimize(toa, ft_stacksize(*a)))
		ft_bisn_aisr(a, b, ft_optimize(toa, ft_stacksize(*a)),
			ft_optimize(tob, ft_stacksize(*b)));
	else if (tob == ft_optimize(tob, ft_stacksize(*b))
		&& toa == ft_optimize(toa, ft_stacksize(*a)))
		ft_bothn(a, b, ft_optimize(toa, ft_stacksize(*a)),
			ft_optimize(tob, ft_stacksize(*b)));
	else
		ft_bisr_aisn(a, b, ft_optimize(toa, ft_stacksize(*a)),
			ft_optimize(tob, ft_stacksize(*b)));
}

void	ft_sortinga(t_stack **a, t_stack **b)
{
	int		index;
	int		i;
	int		counting;
	t_stack	*tmpa;

	i = 0;
	index = 0;
	counting = 0;
	if (ft_stacksize(*a) == 3)
		ft_sorttree(a);
	while (ft_stacksize(*b))
	{
		index = ft_bestmovesindex(*a, *b, index, i);
		ft_moveittoa(a, b, index, i);
	}
	tmpa = *a;
	while (*a)
	{
		if ((*a)->index == 0)
			break ;
		counting++;
		*a = (*a)->next;
	}
	*a = tmpa;
	ft_theend(a, counting);
}
