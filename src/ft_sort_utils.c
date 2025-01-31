/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:32:45 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/31 19:43:06 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_smaller(t_list **stack)
{
	t_list	*smaller;
	int		first;
	int		second;
	int		last;

	first = *(int *)(*stack)->content;
	second = *(int *)((*stack)->next)->content;
	last = *(int *)(ft_lstlast(*stack))->content;
	if (first < second && first < last)
		smaller = *stack;
	else if (second < first && second < last)
		smaller = (*stack)->next;
	else
		smaller = ft_lstlast(*stack);
	return (smaller);
}

 static t_list	*get_bigger(t_list **stack)
{
	t_list	*bigger;
	int		first;
	int		second;
	int		last;

	first = *(int *)(*stack)->content;
	second = *(int *)((*stack)->next)->content;
	last = *(int *)(ft_lstlast(*stack))->content;
	if (first > second && first > last)
		bigger = *stack;
	else if (second > first && second > last)
		bigger = (*stack)->next;
	else
		bigger = ft_lstlast(*stack);
	return (bigger);
}

t_list	*get_nearest(t_list **stack, t_info *info, int compared)
{
	t_list	*nearest;
	int		first;
	int		second;
	int		last;

	first = *(int *)(*stack)->content;
	second = *(int *)((*stack)->next)->content;
	last = *(int *)(ft_lstlast(*stack))->content;
	if (first == compared)
		nearest = *stack;
	else if (second == compared)
		nearest = (*stack)->next;
	else if (last == compared)
		nearest = ft_lstlast(*stack);
	else
	{
		if (compared == info->smallest)
			nearest = get_smaller(stack);
		else
			nearest = get_bigger(stack);
	}
	return (nearest);
}

// void	ft_sort_increase(t_list **a, t_list **b, t_info *info, int tmp_size)
// {
// 	//
// }

// void	ft_sort_decrease(t_list **a, t_list **b, t_info *info, int tmp_size)
// {
// 	//
// }
