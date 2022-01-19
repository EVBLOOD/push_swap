/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moveit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:52:57 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/19 20:12:20 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_conditionofnor(t_stack *b, t_stack *a, int *toa, int *tob)
{
	return ((*tob == ft_optimize(*tob, ft_stacksize(b))
			&& *toa == ft_optimize(*toa, ft_stacksize(a)))
		|| (*tob == ft_optimize(*tob, ft_stacksize(b))
			&& ft_ismidel(toa, ft_stacksize(a)) > 0)
		|| (*toa == ft_optimize(*toa, ft_stacksize(a))
			&& ft_ismidel(tob, ft_stacksize(b)) > 0));
}

int	ft_conditionofrot(t_stack *b, t_stack *a, int *toa, int *tob)
{
	return ((*tob != ft_optimize(*tob, ft_stacksize(b))
			&& *toa != ft_optimize(*toa, ft_stacksize(a)))
		|| (*tob != ft_optimize(*tob, ft_stacksize(b))
			&& ft_ismidel(toa, ft_stacksize(a)) > 0)
		|| (*toa != ft_optimize(*toa, ft_stacksize(a))
			&& ft_ismidel(tob, ft_stacksize(b)) > 0));
}

void	ft_moverot(t_best x, t_stack **a, t_stack **b)
{
	if (x.tmpa != x.a || x.b != x.tmpb)
	{
		if (x.tmpa != x.a)
			ft_bothr(a, b, x.a,
				ft_optimize(x.b, ft_stacksize(*b)));
		else
			ft_bothr(a, b, ft_optimize(x.a, ft_stacksize(*a)),
				x.b);
	}
	else
		ft_bothr(a, b, ft_optimize(x.tmpa, ft_stacksize(*a)),
			ft_optimize(x.tmpb, ft_stacksize(*b)));
}

void	ft_moveittoa(t_stack **a, t_stack **b, int index, int toa)
{
	int		tob;
	t_best	moves;

	tob = ft_getthecount(*b, index);
	toa = ft_movementsfuture(*a, index);
	moves.tmpa = toa;
	moves.tmpb = tob;
	if (ft_conditionofnor(*b, *a, &toa, &tob))
		ft_bothn(a, b, toa, tob);
	else if (ft_conditionofrot(*b, *a, &toa, &tob))
	{
		moves.a = toa;
		moves.b = tob;
		ft_moverot(moves, a, b);
	}
	else if (tob == ft_optimize(tob, ft_stacksize(*b))
		&& toa != ft_optimize(toa, ft_stacksize(*a)))
		ft_bisn_aisr(a, b, ft_optimize(toa, ft_stacksize(*a)),
			ft_optimize(tob, ft_stacksize(*b)));
	else
		ft_bisr_aisn(a, b, ft_optimize(toa, ft_stacksize(*a)),
			ft_optimize(tob, ft_stacksize(*b)));
}
