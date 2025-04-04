/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:57:38 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/27 21:56:33 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	int		i;

	if (!stack || !*stack)
		return ;
	i = ft_lstsize(*stack);
	if (i == 1)
		return ;
	last = ft_lstlast(*stack);
	first = *stack;
	*stack = (*stack)->next;
	last->next = first;
	first->next = NULL;
}

void	d_rotate(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*prev;
	int		i;

	prev = NULL;
	if (!stack || !*stack)
		return ;
	i = ft_lstsize(*stack);
	if (i == 1)
		return ;
	last = ft_lstlast(*stack);
	last->next = *stack;
	while (--i)
	{
		prev = *stack;
		*stack = (*stack)->next;
	}
	*stack = last;
	prev->next = NULL;
}

void	d_reverse_rotate(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
