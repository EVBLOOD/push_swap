/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:39:28 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/22 17:39:11 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
