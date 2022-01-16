/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackman_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:49:40 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/16 07:11:51 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	if (!*lst)
		ft_stackadd_front(lst, new);
	else
	{
		ptr = ft_stacklast((*lst));
		ptr->next = new;
	}
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_stackdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}
