/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:32:49 by sakllam           #+#    #+#             */
/*   Updated: 2022/01/16 08:57:25 by sakllam          ###   ########.fr       */
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
t_stack	*ft_revrserotate(t_stack *all);
t_stack	*ft_rotate(t_stack *all);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stackbeflast(t_stack *lst);
t_stack	*ft_stacknew(int content, int index);
t_stack	*ft_getparams(char **argv, int argc);
void	ft_swap(t_stack *all);
void	ft_push(t_stack **one, t_stack **two);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stackclear(t_stack **lst);
void	ft_stackdelone(t_stack *lst);
void	ft_stackdelone(t_stack *lst);
void	ft_pushtob(t_stack **a, t_stack **b);
void	ft_sortinga(t_stack **a, t_stack **b);
void	ft_sorttree(t_stack	**a);
void	ft_bothr(t_stack **a, t_stack **b, int amoves, int bmoves);
void	ft_bisr_aisn(t_stack **a, t_stack **b, int amoves, int bmoves);
void	ft_bothn(t_stack **a, t_stack **b, int amoves, int bmoves);
void	ft_bisn_aisr(t_stack **a, t_stack **b, int amoves, int bmoves);
void	ft_theend(t_stack **a, int counting);
void	ft_sortstack(t_stack **a);
void	ft_markingtwo(t_stack *data, t_stack *temp, int *number, int tmp);
void	ft_getthelongest(t_stack *data, int *number);
int		ft_stacksize(t_stack *lst);
int		*ft_stackcopy(t_stack *head);
int		ft_optimize(int corrent, int count);
int		ft_movementsfuture(t_stack *a, int corrent);
int		ft_getthecount(t_stack *b, int index);
int		ft_bestmovesindex(t_stack *a, t_stack *b, int index, int correntb);
#endif
