/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackfun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 23:27:19 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/31 19:25:30 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *all)
{
	int	swap;

	swap = all->content;
	all->content = all->next->content;
	all->next->content = swap;
	swap = all->index;
	all->index = all->next->index;
	all->next->index = swap;
	swap = all->push;
	all->push = all->next->push;
	all->next->push = swap;
}

void	ft_push(t_stack **one, t_stack **two)
{
	t_stack	*new_node;

	new_node = ft_stacknew((*one)->content, (*one)->push, (*one)->index);
	ft_stackadd_front(two, new_node);
	*one = (*one)->next;
}

t_stack	*ft_revrserotate(t_stack *all)
{
	t_stack	*tmp;

	tmp = ft_stacklast(all);
	ft_stackbeflast(all)->next = NULL;
	ft_stackadd_front(&all, tmp);
	return (tmp);
}

t_stack	*ft_rotate(t_stack *all)
{
	t_stack	*newhead;

	newhead = all->next;
	all->next = NULL;
	ft_stackadd_back(&newhead, all);
	return (newhead);
}