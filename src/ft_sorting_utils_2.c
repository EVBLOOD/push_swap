/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 06:03:39 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/19 21:08:32 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_movestoallone(t_stack *perf, int *i, int *j)
{
	while (perf)
	{
		if (*j < perf->index)
		{
			(*i)++;
			*j = perf->index;
		}
		perf = perf->next;
	}
}

void	ft_movestoalltwo(t_stack **data, int x, int *i, int *j)
{
	while ((*data)->index != x)
	{
		if (*j < (*data)->index)
		{
			(*i)++;
			*j = (*data)->index;
		}
		*data = (*data)->next;
	}
}

int	**ft_get_the_bestpone(t_stack *data)
{
	t_stack	*temp;
	t_stack	*perf;
	int		**tab;
	int		i[3];

	tab = malloc(sizeof(int *) * ft_stacksize(data));
	temp = data;
	i[0] = 0;
	while (data)
	{
		tab[i[0]] = malloc(sizeof(int) * 2);
		tab[i[0]][1] = data->index;
		i[1] = 0;
		perf = data;
		i[2] = data->index;
		ft_movestoallone(perf, &i[1], &i[2]);
		data = temp;
		ft_movestoalltwo(&data, tab[i[0]][1], &i[1], &i[2]);
		tab[i[0]][0] = i[1];
		data = data->next;
		i[0]++;
	}
	data = temp;
	return (tab);
}

void	ft_marking(t_stack *data, int *number)
{
	int		tmp;
	t_stack	*temp;

	temp = data;
	while (data && data->index != *number)
		data = data->next;
	tmp = data->index;
	ft_markingtwo(data, temp, number, tmp);
	data = temp;
}

void	ft_getthelongest(t_stack *data, int *number)
{
	int		i;
	int		tmp;
	int		**tab;

	tab = ft_get_the_bestpone(data);
	tmp = tab[0][0];
	*number = tab[0][1];
	i = 1;
	while (i < ft_stacksize(data))
	{
		if (tmp < tab[i][0])
		{
			tmp = tab[i][0];
			*number = tab[i][1];
		}
		i++;
	}
	ft_marking(data, number);
	i = -1;
	while (ft_stacksize(data) > ++i)
		free(tab[i]);
	free(tab);
}
