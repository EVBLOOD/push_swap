/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:22:49 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/19 22:50:40 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	int				push;
	struct s_stack	*next;
}	t_stack;
t_stack	*ft_getparams(char **argv, int argc);
int		rest_cond(const char *line, t_stack **a, t_stack **b);
t_stack	*ft_spacestack(char **all);
int		ft_checkisval(char **all);
t_stack	*ft_withspace(char *argv);
void	ft_passornot(t_stack **send);
t_stack	*ft_getparams(char **argv, int argc);
void	ft_swap(t_stack *all);
void	ft_push(t_stack **one, t_stack **two);
t_stack	*ft_revrserotate(t_stack *all);
t_stack	*ft_rotate(t_stack *all);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stackbeflast(t_stack *lst);
t_stack	*ft_stacknew(int content, int index);
int		ft_stacksize(t_stack *lst);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stackdelone(t_stack *lst);
void	ft_stackclear(t_stack **lst);
int		*ft_stackcopy(t_stack *head);

#endif