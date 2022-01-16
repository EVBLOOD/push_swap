/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackman.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:43:14 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/16 08:50:35 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_stackclear(t_stack **lst)
{
	t_stack	*temp;

	temp = NULL;
	if (!*lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		(*lst) = (*lst)->next;
		free(temp);
	}
}

int	*ft_stackcopy(t_stack *head)
{
	int		*tab;
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = head;
	tab = malloc(sizeof(int) * ft_stacksize(head));
	if (!tab)
		return (NULL);
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
