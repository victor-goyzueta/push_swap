/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:43:44 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/30 20:30:37 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sorted(t_list **a, t_info *info)
{
	int		current;
	int		compared;
	int		total;
	t_list	*head;
	
	if (!a || !*a)
		return ;
	total = (int)info->size;
	head = *a;
	if (info->flag && total > 1)
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
	{
		ft_printf("Sorted Stack A");
		exit(EXIT_SUCCESS);
	}
	info->flag = false;
}

void	size_two(t_list **a, t_list **b, t_info *info, int tmp_size)
{
	if (tmp_size != 2)
		return ;
	ss(a, NULL);
	info->flag = true;
	if (info->size == tmp_size)
		push_swap(a, b, info);
}

void	size_three(t_list **sorting, t_list **unused, t_info *info, int tmp_size)
{
	int	first;
	int	second;
	int	last;

	first = *(int *)(*sorting)->content;
	second = *(int *)((*sorting)->next)->content;
	last = *(int *)(ft_lstlast(*sorting))->content;
	if (tmp_size != 3)
		return ;
	if (first > second && first < last)
		ss(sorting, NULL);
	else if (first > second && first > last)
		rr(sorting, NULL);
	else
		rrr(sorting, NULL);
	info->flag = true;
	if (info->size == tmp_size)
		push_swap(sorting, unused, info);
}

void	push_swap(t_list **a, t_list **b, t_info *info)
{
	check_sorted(a, info);
	size_two(a, b, info, info->size);
	size_three(a, b, info, info->size);
	ft_sort_a(a, b, info, info->size);
}
