/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackcmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:44:08 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/18 02:39:47 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_swap(t_stack *all)
{
	int	swap;

	swap = all->content;
	all->content = all->next->content;
	all->next->content = swap;
	swap = all->index;
	all->index = all->next->index;
	all->next->index = swap;
}

void	ft_push(t_stack **one, t_stack **two)
{
	t_stack	*new_node;
	t_stack	*tmp;

	tmp = *one;
	new_node = ft_stacknew((*one)->content, (*one)->index);
	ft_stackadd_front(two, new_node);
	*one = (*one)->next;
	free(tmp);
}

t_stack	*ft_revrserotate(t_stack *all)
{
	t_stack	*tmp;

	if (ft_stacksize(all) <= 1)
		return (all);
	tmp = ft_stacklast(all);
	ft_stackbeflast(all)->next = NULL;
	ft_stackadd_front(&all, tmp);
	return (tmp);
}

t_stack	*ft_rotate(t_stack *all)
{
	t_stack	*newhead;

	if (ft_stacksize(all) <= 1)
		return (all);
	newhead = all->next;
	all->next = NULL;
	ft_stackadd_back(&newhead, all);
	return (newhead);
}
