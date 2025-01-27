/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:57:38 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/27 01:36:26 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*prev;
	int		i;
	
	if (!stack || !*stack)
		return ;
	i = ft_lstsize(*stack);
	last = ft_lstlast(*stack);
	first = *stack;
	while (i)
	{
		prev = *stack;
		*stack = (*stack)->next;
	}
	ft_printf("First: %p\n", first);
	ft_printf("Prev: %p\n", prev);
	ft_printf("Last: %p\n", last);
}
