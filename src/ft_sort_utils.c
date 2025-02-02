/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:32:45 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/02 21:27:28 by vgoyzuet         ###   ########.fr       */
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

bool	is_sorted(t_list **a, t_list **b)
{
	int		current;
	int		compared;
	t_list	*head;

	if (!b)
		head = *a;
	else
		head = *b;
	current = *(int *)head->content;
	while (head->next)
	{
		head = head->next;
		compared = *(int *)head->content;
		if (current > compared && !b)
			return (false);
		if (current < compared && !a)
			return (false);
		current = *(int *)head->content;
	}
	return (true);
}

void	check_success(t_list **a, t_info *info)
{
	int		current;
	int		compared;
	int		total;
	t_list	*head;

	if (!a || !*a)
		return ;
	total = (int)info->size;
	head = *a;
	if (total > 1)
	{
		current = *(int *)head->content;
		while (head->next)
		{
			head = head->next;
			compared = *(int *)head->content;
			if (current > compared)
				break ;
			current = *(int *)head->content;
			total--;
		}
	}
	if (!head->next && total == 1)
		exit(EXIT_SUCCESS);
}
