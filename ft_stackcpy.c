/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 23:21:54 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/24 18:16:07 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_stackcopy(t_stack *head)
{
	int		*tab;
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = head;
	tmp = malloc(sizeof(t_stack) * ft_stacksize(head));
	head = tmp;
	while (head)
	{
		tab[i] = head->content;
		head = head->next;
		i++;
	}
	head = tmp;
	return (tab);
}