/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:43:44 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/31 20:10:33 by vgoyzuet         ###   ########.fr       */
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
	(void)b;
	if (tmp_size == 2)
	{
		ss(a, NULL);
		info->flag = true;
		check_sorted(a, info);
	}
}

void	size_three(t_list **a, t_list **b, t_info *info, int tmp_size)
{
	int	first;
	int	second;
	int	last;

	if (tmp_size == 3)
	{
		first = *(int *)(*a)->content;
		second = *(int *)((*a)->next)->content;
		last = *(int *)(ft_lstlast(*a))->content;
		if (first > second && first < last)
			ss(a, NULL);
		else if (first > second && first > last)
			rr(a, NULL);
		else
			rrr(a, NULL);
		info->flag = true;
	}
	if (info->size == 3)
		push_swap(a, b, info, info->size);
}

void	size_five(t_list **a, t_list **b, t_info *info, int tmp_size)
{
	t_list	*smaller;

	(void)tmp_size;
	if (tmp_size > 3)
	{
		smaller = get_nearest(a, info, info->smallest);
		if (*(int *)smaller->content != info->smallest)
			rrr(a, NULL);
		else if (smaller == *a)
			pb(a, b);
		else
			size_five(a, b, info, ft_lstsize(*a));
	}
	else
	{
		size_three(a, b, info, 3);
		pa(b, a);
	}
	info->flag = true;
	check_sorted(a, info);
}

void	push_swap(t_list **a, t_list **b, t_info *info, int	tmp_size)
{
	(void)tmp_size;
	check_sorted(a, info);
	size_two(a, b, info, info->size);
	size_three(a, b, info, info->size);
	size_five(a, b, info, info->size);
}
