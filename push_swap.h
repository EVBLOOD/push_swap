/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 19:30:08 by sakllam           #+#    #+#             */
/*   Updated: 2021/12/31 19:23:43 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>
typedef struct s_stack{
	int				content;
	int				push;
	int				index;
	struct s_stack	*next;
}	t_stack;
t_stack	*ft_getparams(char **argv, int nb);
int	ft_thereisspace(char *str);
int	ft_isvariables(char *str);
void	ft_clean(char **values);
void	ft_getintegerbeta(t_stack **send, char **values);
void	ft_error1(char **values);
void	ft_error2(t_stack **send, char **values);
void	ft_getinteger(t_stack **send, char **values);
t_stack	*ft_deuxatoi(char **values);
t_stack	*ft_getvalue(char *str);
t_stack	*ft_multiatoi(char **values);
t_stack	*ft_getmultiple(char **argv);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stackclear(t_stack **lst);
void	ft_stackdelone(t_stack *lst);
int	*ft_stackcopy(t_stack *head);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stacknew(int content, int push, int index);
int	ft_stacksize(t_stack *lst);
t_stack	*ft_stackbeflast(t_stack *lst);
void	ft_swap(t_stack *all);
void	ft_push(t_stack **one, t_stack **two);
t_stack	*ft_revrserotate(t_stack *all);
t_stack	*ft_rotate(t_stack *all);
void	ft_checkdata(t_stack *cmp);
void	ft_sorttwo(t_stack **data, int size);
#endif