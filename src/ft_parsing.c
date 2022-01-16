/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:23:31 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/16 08:48:50 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_spacestack(char **all)
{
	t_stack	*send;
	t_stack	*head;
	int		i;

	head = NULL;
	i = -1;
	while (all[++i])
	{
		send = ft_stacknew(ft_atoi(all[i]), 0);
		if (!send)
		{
			ft_stackclear(&head);
			return (NULL);
		}
		ft_stackadd_back(&head, send);
	}
	return (head);
}

int	ft_checkisval(char **all)
{
	int	i;
	int	j;

	i = 0;
	while (all[i])
	{
		j = 0;
		if (all[i][j] == '-')
			j++;
		while (all[i][j])
		{
			if (!ft_isdigit(all[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	*ft_withspace(char *argv)
{
	t_stack	*send;
	char	**all;
	int		i;

	i = -1;
	send = NULL;
	all = ft_split(argv, ' ');
	if (ft_checkisval(all))
		send = ft_spacestack(all);
	while (all[++i])
		free(all[i]);
	free (all);
	return (send);
}

void	ft_passornot(t_stack **send)
{
	t_stack	*tmp;
	t_stack	*cmp;
	int		i;

	tmp = *send;
	while (*send)
	{
		cmp = tmp;
		i = 0;
		while (cmp)
		{
			if (cmp->content == (*send)->content)
				i++;
			cmp = cmp->next;
		}
		if (i > 1)
		{
			ft_stackclear(&tmp);
			break ;
		}
		*send = (*send)->next;
	}
	*send = tmp;
}

t_stack	*ft_getparams(char **argv, int argc)
{
	t_stack	*send;

	send = NULL;
	if (argc == 2)
	{
		if (ft_strchr(argv[1], ' '))
			send = ft_withspace(argv[1]);
		else if (ft_checkisval(&argv[1]))
			send = ft_spacestack(&argv[1]);
	}
	else
	{
		if (ft_checkisval(&argv[1]))
			send = ft_spacestack(&argv[1]);
	}
	ft_passornot(&send);
	return (send);
}
