/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bestmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:47:41 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/19 21:09:58 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_first(int *total, int corrent, int correntb, t_stack *tmpa)
{
	corrent = ft_optimize(corrent, ft_stacksize(tmpa));
	correntb = correntb + 1;
	if (corrent > correntb)
		*total = corrent;
	else
		*total = correntb;
}

int	ft_second(int corrent, int correntb, t_stack *tmpa, t_stack *tmpb)
{
	int	total;

	corrent = ft_optimize(corrent, ft_stacksize(tmpa));
	correntb = ft_optimize(correntb, ft_stacksize(tmpb));
	if (corrent > correntb)
		total = corrent;
	else
		total = correntb;
	return (total);
}

int	ft_conditionone(int *corrent, t_stack *tmpa, t_stack *tmpb, int *correntb)
{
	int	tmpbv;
	int	tmpav;

	tmpbv = *correntb;
	tmpav = *corrent;
	if ((ft_isanrorrr(*corrent, tmpa) == 'r'
			&& ft_isanrorrr(*correntb, tmpb) == 'r')
		|| (ft_isanrorrr(*correntb, tmpb) == 'n'
			&& ft_isanrorrr(*corrent, tmpa) == 'n')
		|| (ft_isanrorrr(*corrent, tmpa) == 'r'
			&& ft_ismidel(&tmpbv, ft_stacksize(tmpb)) > 0)
		|| (ft_isanrorrr(*correntb, tmpb) == 'r'
			&& ft_ismidel(&tmpav, ft_stacksize(tmpa)) > 0)
		|| (ft_isanrorrr(*corrent, tmpa) == 'n'
			&& ft_ismidel(&tmpbv, ft_stacksize(tmpb)) > 0)
		|| (ft_isanrorrr(*correntb, tmpb) == 'n'
			&& ft_ismidel(&tmpav, ft_stacksize(tmpa)) > 0))
	{
		*correntb = tmpbv;
		*corrent = tmpav;
		return (1);
	}
	return (0);
}

int	ft_theelse(t_best corrent, int correntb, t_stack *tmpa, t_stack *tmpb)
{
	int	total;

	corrent.a = ft_optimize(ft_movementsfuture(tmpa, corrent.b),
			ft_stacksize(tmpa));
	correntb = ft_optimize(correntb, ft_stacksize(tmpb));
	total = corrent.a + correntb;
	return (total);
}

int	ft_co(t_best corrent, t_stack *tmpa, t_stack *tmpb, int correntb)
{
	int	tmpbv;
	int	tmpav;
	int	total;

	tmpbv = correntb;
	tmpav = corrent.a;
	if (ft_conditionone(&tmpav, tmpa, tmpb, &tmpbv))
	{
		if (tmpbv != correntb)
			ft_first(&total, corrent.a, correntb, tmpa);
		else if (tmpav != corrent.a)
			ft_first(&total, correntb, corrent.a, tmpb);
		else
			total = ft_second(corrent.a, correntb, tmpa, tmpb);
	}
	else
		total = ft_theelse(corrent, correntb, tmpa, tmpb);
	return (total);
}
