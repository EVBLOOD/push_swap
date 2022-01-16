/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:59:16 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/16 08:53:47 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_countforstart(t_stack *start, int *tmp, int index)
{
	int		answer;
	t_stack	*stmp;
	int		counting;

	counting = 0;
	answer = 0;
	stmp = start;
	*tmp = start->index;
	while (start)
	{
		counting++;
		if (index > start->index)
		{
			*tmp = start->index;
			answer = counting;
		}
		else
			break ;
		start = start->next;
	}
	start = stmp;
	return (answer);
}

int	ft_countforhead(t_stack *head, int *tmp, int index, int end)
{
	int		answer;
	t_stack	*stmp;
	int		counting;

	counting = 0;
	stmp = head;
	answer = 0;
	while (head && head->index != end)
	{
		counting++;
		if (index > head->index)
		{
			*tmp = head->index;
			answer = counting;
		}
		else
			break ;
		head = head->next;
	}
	head = stmp;
	return (answer);
}

int	ft_letscount(t_stack *head, t_stack *start, int index)
{
	int	counting;
	int	answer;
	int	startindex;
	int	tmp;

	counting = 0;
	answer = 0;
	tmp = 0;
	startindex = start->index;
	if (head != start)
	{
		answer = ft_countforstart(start, &tmp, index);
		startindex = ft_countforhead(head, &tmp, index, startindex);
		if (answer < ft_stacksize(start))
			return (answer + (ft_stacksize(head) - ft_stacksize(start)));
		else
			return (startindex);
	}
	else
		answer = ft_countforstart(start, &tmp, index);
	return (answer);
}

int	ft_movementsfuture(t_stack *a, int corrent)
{
	t_stack	*head;
	t_stack	*start;
	int		index;

	head = a;
	index = a->index;
	while (a)
	{
		if (index >= a->index)
		{
			index = a->index;
			start = a;
		}
		a = a->next;
	}
	a = head;
	index = ft_letscount(head, start, corrent);
	return (index);
}

int	ft_optimize(int corrent, int count)
{
	if (corrent > count / 2)
		return (count - corrent);
	return (corrent);
}
