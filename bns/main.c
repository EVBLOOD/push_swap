/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:24:13 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/19 22:51:52 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap.h"
#include "get_next_line/get_next_line.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:24:13 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/19 22:46:54 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap.h"
#include "get_next_line/get_next_line.h"

void	ft_sorted(t_stack *a, t_stack *b)
{
	if (ft_stacksize(b) != 0)
	{
		write (1, "KO\n", 3);
		return ;
	}
	while (a)
	{
		if (a->next && a->content > a->next->content)
		{
			write (1, "KO\n", 3);
			return ;
		}
		a = a->next;
	}
	write (1, "OK\n", 3);
}

int	ft_cmnds_(const char *line, t_stack **a, t_stack **b)
{
	int	size;

	size = ft_strlen(line);
	if (!ft_strncmp(line, "ra\n", size))
		*a = ft_rotate(*a);
	else if (!ft_strncmp(line, "rb\n", size))
		*b = ft_rotate(*b);
	else if (!ft_strncmp(line, "rr\n", size))
	{
		*b = ft_rotate(*b);
		*a = ft_rotate(*a);
	}
	else if (!ft_strncmp(line, "rra\n", size))
		*a = ft_revrserotate(*a);
	else if (!ft_strncmp(line, "rrb\n", size))
		*b = ft_revrserotate(*b);
	else
		if (!rest_cond(line, a, b))
			return (0);
	return (1);
}

int	ft_cmnds(const char *line, t_stack **a, t_stack **b)
{
	int	size;

	size = ft_strlen(line);
	if (!ft_strncmp(line, "sa\n", size))
		ft_swap(*a);
	else if (!ft_strncmp(line, "sb\n", size))
		ft_swap(*b);
	else if (!ft_strncmp(line, "ss\n", size))
	{
		ft_swap(*a);
		ft_swap(*b);
	}
	else if (!ft_strncmp(line, "pa\n", size))
		ft_push(b, a);
	else if (!ft_strncmp(line, "pb\n", size))
		ft_push(a, b);
	else
		if (!ft_cmnds_(line, a, b))
			return (0);
	return (1);
}

int	ft_wo(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!ft_cmnds(line, a, b))
		{
			free(line);
			ft_stackclear(a);
			ft_stackclear(b);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
		a = ft_getparams(argv, argc);
	if (argc == 1 || !a)
	{
		ft_putstr_fd("error", 2);
		exit (1);
	}
	if (!ft_wo(&a, &b))
		return (0);
	ft_sorted(a, b);
	ft_stackclear(&a);
	ft_stackclear(&b);
	return (1);
}
