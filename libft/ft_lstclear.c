/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:52:02 by sakllam           #+#    #+#             */
/*   Updated: 2021/11/11 00:00:42 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	temp = NULL;
	if (!*lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		(*lst) = (*lst)->next;
		del(temp->content);
		free(temp);
	}
}
