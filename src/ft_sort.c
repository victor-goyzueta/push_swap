/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:36:35 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/30 21:17:35 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_smaller(t_list **stack)
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

t_list	*get_bigger(t_list **stack)
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

void ft_sort_b(t_list **a, t_list **b, t_info *info, int tmp_size)
{
	/*sort bigger to smaller*/
	/*if firstB is firstA nearestBigger (pa)*/
	if (info->size == tmp_size)
	{
		while (tmp_size--)
			pa(b, a);
	}		
	else
		ft_sort_a(a, b, info, info->size);

void	ft_sort_a(t_list **a, t_list **b, t_info *info, int tmp_size)
{
	t_list	*nearest;

	if (ft_lstsize(*b) >= 3)
		ft_sort_b(b, a, info, ft_lstsize(*b));
	nearest = get_nearest(a, info, info->smallest);
	if (nearest == *a)
		pb(a, b);
	else if (nearest == (*a)->next)
	{
		ss(a, NULL);
		pb(a, b);
	}
	else
	{
		rrr(a, NULL);
		pb(a, b);
	}
	info->flag = true;
	if (info->size == tmp_size)
		push_swap(a, b, info);
}
