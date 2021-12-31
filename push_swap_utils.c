/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:34:57 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/31 21:47:40 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_thereisspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_isvariables(char *str)
{
	int	i;
	if (ft_thereisspace(str))
		return (1);
	else if (ft_atoi(str) > 0 || (str[0] == '0' && !str[1]))
		return (1);
	return (0);

}

void	ft_error1(char **values)
{
	int	i;

	ft_putstr_fd("error\n", 2);
	if (values)
	{
		i = -1;
		while (values[++i])
			free(values[i]);
		free(values);
	}
	exit (0);
}

void	ft_error2(t_stack **send, char **values)
{
	ft_stackclear(send);
	ft_error1(values);
}

void	ft_clean(char **values)
{
	int	i;

	i = 0;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
}

void	ft_getinteger(t_stack **send, char **values)
{
	int		i;
	t_stack	*new;

	i = 0;
	*send = NULL;
	while (values[i])
	{
		if (ft_isvariables(values[i]))
		{
			new = ft_stacknew(ft_atoi(values[i]), 0, 0);
			ft_stackadd_back(send, new);
		}
		else
			ft_error2(send, values);
		i++;
	}
	ft_clean(values);
}

t_stack	*ft_deuxatoi(char **values)
{
	t_stack	*send;

	ft_getinteger(&send, values);
	return (send);
}

t_stack	*ft_getvalue(char *str)
{
	char	**values;
	t_stack		*send;
	
	values = NULL;
	if (ft_thereisspace(str))
	{
		values = ft_split(str, ' ');
		send = ft_deuxatoi(values);
	}
	else if (ft_atoi(str) > 0 || (str[0] == '0' && !str[1]))
	{
		send = malloc(sizeof(t_stack) * 1);
		if (!send)
			ft_error1(values);
		send->content = ft_atoi(str);
		send->next = NULL;
	}
	return (send);
}
void	ft_getintegerbeta(t_stack **send, char **values)
{

	int		i;
	t_stack	*new;

	i = 0;
	*send = NULL;
	while (values[i])
	{
		if (ft_isvariables(values[i]) && !ft_thereisspace(values[i]))
		{
			new = ft_stacknew(ft_atoi(values[i]), 0 , 0);
			ft_stackadd_back(send, new);
		}
		else
		{
			ft_stackclear(send);
			ft_putstr_fd("error", 2);
			exit (0);
		}
		i++;
	}
}

t_stack	*ft_getmultiple(char **argv)
{
	t_stack	*send;

	ft_getintegerbeta(&send, argv);
	return (send);
}

t_stack	*ft_getparams(char **argv, int nb)
{
	t_stack	*send;
	
	send = NULL;
	if (nb == 2 && ft_isvariables(argv[1]))
		send = ft_getvalue(argv[1]);
	else if (nb > 2)
		send = ft_getmultiple(&argv[1]);
	else
	{
		ft_putstr_fd("error", 2);
		exit (0);
	}
	return (send);
}

void	ft_checkdata(t_stack *data)
{
	t_stack	*cmp;
	
	while (data)
	{
		cmp = data->next;
		while (cmp)
		{
			if (data->content == cmp->content)
				ft_error2(&data, NULL);
			cmp = cmp->next;
		}
		data = data->next;
	}
}

void	ft_sortone(t_stack **data, int size)
{

}
int	ft_check_equa_stacka(t_stack *data)
{
	int	index;
	index = 0;
	while (data)
	{
		if (data->next && data->content > data->next->content)
			return (index);
		index++;
		data = data->next;
	}
	return (-1);
}

int	ft_check_equa_stackb(t_stack *data)
{
	int	index;
	index = 0;
	while (data)
	{
		if (data->next && data->content < data->next->content)
			return (index);
		index++;
		data = data->next;
	}
	return (-1);
}

void	ft_swapcase(t_stack **a, t_stack **b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;

	tmpa = *a;
	tmpb = *b;
	if ((*a)->next->content < (*a)->content && (*b)->next->content > (*b)->content)
	{
	printf("|%d|", (*b)->content);
	printf("|%d|", (*b)->next->content);
	printf("|%d|", (*a)->content);
	printf("|%d|", (*a)->next->content);
		ft_swap(*a);
		ft_swap(*b);
		ft_putstr_fd("ss", 1);
	}
	else if ((*b)->next->content < (*b)->content && ft_stacksize(tmpb) > 2)
	{
		ft_swap(*b);
		ft_putstr_fd("sb", 1);
	}
	else if ((*a)->next->content > (*a)->content && ft_stacksize(tmpa) > 2)
	{
		ft_swap(*a);
		ft_putstr_fd("sa", 1);
	}
}

void	ft_rotatecase(t_stack **a, t_stack **b)
{
	ft_swapcase(a, b);
	if ((*a)->content > ft_stacklast(*a)->content && (*b)->content < ft_stacklast(*b)->content)
	{
		ft_rotate(*a);
		ft_rotate(*b);
		ft_putstr_fd("rr", 1);
	}
	else if ((*a)->content > ft_stacklast(*a)->content)
	{
		ft_rotate(*a);
		ft_putstr_fd("ra", 1);
	}
	else
	{
		ft_rotate(*b);
		ft_putstr_fd("rb", 1);
	}
}

void	ft_reverserotatecase(t_stack **a, t_stack **b)
{
	ft_swapcase(a, b);
	ft_rotatecase(a, b);
	if ((*a)->content < ft_stacklast(*a)->content && (*b)->content > ft_stacklast(*b)->content && ft_stacksize(*b) > 2)
	{
		ft_revrserotate(*a);
		ft_revrserotate(*b);
		ft_putstr_fd("rr", 1);
	}
	else if ((*a)->content > ft_stacklast(*a)->content)
	{
		ft_revrserotate(*a);
		ft_putstr_fd("ra", 1);
	}
	else if ((*b)->content < ft_stacklast(*b)->content && ft_stacksize(*b) > 2)
	{
		ft_revrserotate(*b);
		ft_putstr_fd("rb", 1);
	}
}

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

void	ft_top(t_stack *tmpa, int index, t_stack **a, t_stack **b)
{
	int	tmpind;
	
	tmpind = index;
	while (tmpind > 0)
	{
		*a = ft_rotate(*a);
		write(1, "ra\n", 3);
		puts("?");
		tmpind--;
	}
	ft_push(a, b);
	write(1, "pb\n", 3);
}

void	ft_buttom(t_stack *tmpa, int index, t_stack **a, t_stack **b)
{
	int	tmpind;

	tmpind = ft_stacksize(tmpa) - index; 
	while (tmpind > 0)
	{
		*a = ft_revrserotate(*a);
		puts("?");
		write(1, "ra\n", 3);
		tmpind--;
	}
	ft_push(a, b);
	write(1, "pb\n", 3);
}
// void	ft_pushing_intoit(t_stack **a, t_stack **b, int i, int *tabtmp)
// {
// 	int	index;
// 	t_stack	*tmpa;
// 	t_stack *tmp;
// 	int	j;

// 	while (*a)
// 	{
// 		j = i / 4;
// 		printf("\nelements:%d\n", (*a)->content);
// 		while (j >= 0)
// 		{
// 			if ((*a)->content == tabtmp[j])
// 			{
// 				if (index > ft_stacksize(tmpa) / 2)
// 					ft_buttom(tmpa, index, a, b);
// 				else
// 					ft_top(tmpa, index, a, b);
// 				tmp = *a;
// 				break ;
// 			}
// 			j--;
// 		}
// 		*a = (*a)->next;
// 		index++;
// 	}
// 	*a = tmp;
// }
int	ft_coppyto(t_stack **data, int *tab)
{
	int		i;
	t_stack	*tmpstack;

	i = 0;
	tmpstack = *data;
	while (*data)
	{
		tab[i] = (*data)->content;
		*data = (*data)->next;
		i++;
	}
	*data = tmpstack;
	return (i);
}

void	ft_giveindexs(t_stack *data, int *tab)
{
	t_stack	*tmp;
	int		i;
	int		j;

	tmp = data;
	i = ft_stacksize(data);
	while (data)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j] == data->content)
			{
				data->index = j;
				break;
			}
			j++;
		}
		data = data->next;
	}
	data = tmp;
}

int	ft_getthelongest(t_stack *data, int *number)
{
	int	act;
	int	perf;
	t_stack	*tmp;

	act = 0;
	perf = act;
	tmp = data;
	while (data)
	{
		if (data->next && data->index + 1 == data->next->index)
			act++;
		if (data->next && data->index + 1 != data->next->index)
		{
			if (perf < act)
			{
				perf = act;
				*number = data->content;
			}
			act = 0;
		}
		data = data->next;
	}
	data = tmp;
	return (perf);
}

// int	ft_checkindex(t_stack **a, int start, int number)
// {

// }
void	ft_pushing_intoit(t_stack **a, t_stack **b, int i, int number)
{
	t_stack	*tmp;
	int		tot;
	int		tmpi;

	tmp = *a;
	tot = i + number;
	tmpi = i;
	while (*a)
	{
		if (i != (*a)->index)
		{
			ft_push(a, b);
			ft_putstr_fd("pa\n", 1);
			tmp = *a;
		}
		else
		{
			i++;
			*a = (*a)->next;
		}
		if (i > tot)
			break;
	}
	i = tmpi;
	*a = tmp;
	while (*a)
	{
		if (i != (*a)->index)
		{
			puts("123\n");
			*a = ft_revrserotate(tmp);
			// exit (2);
			ft_push(a, b);
			tmp = *a;
			i = tmpi;
			*a = (*a)->next;
		}
		else
		{
			puts("1543\n");
			i++;
			*a = (*a)->next;
		}
		if (ft_stacksize(tmp) - number == -1)
			break;
	}
	
	*a = tmp;
	while (*a)
	{
		printf("%d", (*a)->index);
		*a = (*a)->next;
	}
}

void	ft_sorttwo(t_stack **data, int size)
{
	int	i;
	int *tabtmp;
	int	number;
	t_stack	*b;

	b = NULL;
	// while (ft_stacksize(*data) > 3)
	// {
		tabtmp = malloc(sizeof(int) * ft_stacksize(*data));
		i = ft_coppyto(data, tabtmp);
		ft_sort_int_tab(tabtmp, i);
		ft_giveindexs(*data, tabtmp);
		free(tabtmp);
		number = ft_getthelongest(*data, &i);
		i = i - number;
		// printf("index: %d|number: %d\n", i, number);
		ft_pushing_intoit(data, &b, i, number);
		// puts("is it here?");
	// }
}
