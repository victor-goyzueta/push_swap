/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:43:44 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/31 21:54:20 by vgoyzuet         ###   ########.fr       */
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

void	size_two(t_list **a, t_info *info, int tmp_size)
{
	if (tmp_size == 2)
		ss(a, NULL);
	info->flag = true;
}

void	size_three(t_list **a, t_info *info, int tmp_size)
{
	t_list	*smallest;
	t_list	*biggest;

	if (tmp_size == 3)
	{
		smallest = get_nearest(a, info, info->smallest);
		biggest = get_nearest(a, info, info->biggest);
		if (*a == smallest)
		{
			rrr(a, NULL);
			ss(a, NULL);
		}
		else if (*a == biggest && ft_lstlast(*a) == smallest)
		{
			rr(a, NULL);
			ss(a, NULL);
		}
		else if (*a == biggest&& ft_lstlast(*a) != smallest)
			rr(a, NULL);
		else if (ft_lstlast(*a) == biggest)
			ss(a, NULL);
		else
			rrr(a, NULL);
	}
	info->flag = true;
}

void	size_five(t_list **a, t_list **b, t_info *info, int tmp_size)
{
	t_list	*smaller;

	smaller = get_nearest(a, info, info->smallest);
	if (tmp_size > 3 && ft_lstsize(*b) < 1)
	{
		if (info->smallest == *(int *)(*a)->content || smaller == *a)
			pb(a, b);
		else if (smaller == (*a)->next)
		{
			ss(a, NULL);
			pb(a, b);
		}
		else
			rrr(a, NULL);
		size_five(a, b, info, ft_lstsize(*a));
	}
	else
	{
		size_three(a, info, 3);
		pa(b, a);
		if (*(int *)(*a)->content > *(int *)(*a)->next->content)
			ss(a, NULL);
	}
	info->flag = true;
}

void	push_swap(t_list **a, t_list **b, t_info *info, int	tmp_size)
{
	(void)tmp_size, (void)b;
	check_sorted(a, info);
	size_two(a, info, info->size);
	size_three(a, info, info->size);
	check_sorted(a, info);
	size_five(a, b, info, info->size);
	check_sorted(a, info);
}
