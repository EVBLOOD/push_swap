/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:31:54 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/31 19:23:07 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int content, int push, int index)
{
	t_stack	*p;

	p = (t_stack *) malloc(sizeof(t_stack));
	if (!p)
		return (NULL);
	p->content = content;
	p->index = index;
	p->push = push;
	p->next = NULL;
	return (p);
}
