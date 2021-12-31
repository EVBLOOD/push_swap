/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:59:23 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/31 12:36:56 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *lst)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	if (!lst)
		return (0);
	tmp = lst;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	lst = tmp;
	return (i);
}
