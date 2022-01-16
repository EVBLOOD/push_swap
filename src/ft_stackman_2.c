/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackman_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:47:36 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/16 05:47:42 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

t_stack	*ft_stacknew(int content, int index)
{
	t_stack	*p;

	p = (t_stack *) malloc(sizeof(t_stack));
	if (!p)
		return (NULL);
	p->content = content;
	p->index = index;
	p->next = NULL;
	return (p);
}

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
