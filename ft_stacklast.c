/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacklast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:23:08 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/24 00:14:16 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return (NULL);
	while (lst)
	{
		temp = lst;
		lst = lst->next;
	}
	return (temp);
}

t_stack	*ft_stackbeflast(t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return (NULL);
	while (lst->next)
	{
		temp = lst;
		lst = lst->next;
	}
	return (temp);
}
