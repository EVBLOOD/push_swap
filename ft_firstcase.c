// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_firstcase.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/12/24 00:30:29 by sakllam           #+#    #+#             */
// /*   Updated: 2021/12/24 23:14:42 by sakllam          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// int	ft_position(t_stack *head, int value)
// {
// 	t_stack	*tmp;
// 	int		pos;

// 	tmp = head;
// 	pos = 0;
// 	while (tmp)
// 	{
// 		if (tmp->content == value)
// 			return (pos);
// 		pos++;
// 		tmp = tmp->next;
// 	}
// 	return (pos);
// }

// void	ft_sort_int_tab(int *tab, int size)
// {
// 	int	i;
// 	int	swp;
// 	int	j;

// 	i = 0;
// 	while (i < size - 1)
// 	{
// 		j = i + 1;
// 		while (j < size)
// 		{
// 			if (tab[i] > tab[j])
// 			{
// 				swp = tab[j];
// 				tab[j] = tab[i];
// 				tab[i] = swp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	ft_sorttree(t_stack *head)
// {
// 	int		*tab;
// 	int		pos;
// 	t_stack	*tmp;

// 	tmp = head;
// 	tab = ft_stackcopy(head);
// 	head = tmp;
// 	ft_sort_int_tab(tab, ft_stacksize(head));
// 	head = tmp;
// 	if (head->content < head->next->content && head->next->content > head->next->next->content
// 		&& head->content > head->next->next->content)
// 		head = ft_revrserotate(head);
// 	pos = ft_position(head, tab[2]);
// 	if (pos == 1)
// 		head = ft_revrserotate(head);
// 	else if (pos == 2)
// 		head = ft_swap(head);
// 	pos = ft_position(head, tab[1]);
// 	if (pos == 1)
// 		head = ft_swap(head);
// }