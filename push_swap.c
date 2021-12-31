/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:29:54 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/30 15:36:55 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*data;
	t_stack	*tmp;
	int		size;

	data = ft_getparams(argv, argc);
	tmp = data;
	ft_checkdata(data);
	data = tmp;
	size = ft_stacksize(data);
	data = tmp;

	// if (size == 3)
		// ft_sortone(&data, size);
	 if (size > 3 && size <= 100)
		ft_sorttwo(&data, size);
	// else
		// ft_sorttree(&data, size);
	ft_stackclear(&data);
	free(data);
	return (1);
}