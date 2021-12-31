/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:23:00 by sakllam           #+#    #+#             */
/*   Updated: 2021/11/08 15:54:23 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*s;
	t_list	*temp;
	t_list	*head;

	if (!lst)
		return (NULL);
	temp = lst;
	head = NULL;
	while (lst)
	{
		s = ft_lstnew(f(lst->content));
		if (!s)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		ft_lstadd_back(&head, s);
		lst = lst->next;
	}
	return (head);
}
