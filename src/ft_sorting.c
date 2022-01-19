/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:52:14 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/17 23:08:17 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	swp;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				swp = tab[j];
				tab[j] = tab[i];
				tab[i] = swp;
			}
			j++;
		}
		i++;
	}
}

void	ft_indexs(int *tab, t_stack *a)
{
	int		i;
	int		limit;
	t_stack	*tmp;

	tmp = a;
	i = 0;
	limit = ft_stacksize(a);
	while (i < limit)
	{
		while (a)
		{
			if (a->content == tab[i])
			{
				a->index = i;
				break ;
			}
			a = a->next;
		}
		i++;
		a = tmp;
	}
	free(tab);
}

void	ft_sortfive(t_stack	**a)
{
	t_stack	*b;

	b = 0;
	while (ft_stacksize(*a) != 3)
	{
		if ((*a)->index < 2)
		{
			ft_push(a, &b);
			ft_putstr_fd("pb\n", 1);
		}
		else
		{
			*a = ft_revrserotate(*a);
			ft_putstr_fd("rra\n", 1);
		}
	}
	ft_sorttree(a);
	if (b->index < b->next->index)
	{
		ft_swap(b);
		ft_putstr_fd("sb\n", 1);
	}
	ft_push(&b, a);
	ft_push(&b, a);
	ft_putstr_fd("pa\npa\n", 1);
}

void	ft_sortstack(t_stack **a)
{
	int		*tab;
	int		start;
	int		count;
	t_stack	*b;

	b = NULL;
	count = 0;
	tab = ft_stackcopy(*a);
	ft_sort_int_tab(tab, ft_stacksize(*a));
	ft_indexs(tab, *a);
	if (ft_stacksize(*a) == 5)
		ft_sortfive(a);
	ft_getthelongest(*a, &start);
	ft_pushtob(a, &b);
	ft_sortinga(a, &b);
}
