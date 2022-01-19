/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_utils_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:59:54 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/18 10:01:38 by sakllam          ###   ########.fr       */
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

char	ft_isanrorrr(int moves, t_stack *x)
{
	if (ft_optimize(moves, ft_stacksize(x)) != moves)
		return ('r');
	return ('n');
}

int	ft_ismidel(int *corrent, int size)
{
	int	x;

	x = size / 2;
	if (size % 2 == 0 && size / 2 == *corrent)
		return (*corrent);
	else if (size % 2 == 1 && x == *corrent)
	{
		(*corrent)++;
		return (*corrent);
	}
	return (-1);
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
