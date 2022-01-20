/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 05:20:29 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/20 01:13:20 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*data;

	data = NULL;
	if (argc > 1)
		data = ft_getparams(argv, argc);
	if (argc == 1 || !data)
	{
		ft_putstr_fd("error", 2);
		exit (1);
	}
	ft_sortstack(&data);
	ft_stackclear(&data);
	return (0);
}
