/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:36:35 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/31 19:31:39 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_b(t_list **a, t_list **b, t_info *info, int tmp_size)
{
	/*sort bigger to smaller*/
	/*if firstB is firstA nearestBigger (pa)*/
	int	first;
	int	second;
	int	last;

	(void)info;
	first = *(int *)(*b)->content;
	second = *(int *)((*b)->next)->content;
	last = *(int *)(ft_lstlast(*b))->content;
	if (tmp_size == 2 && first < second)
		size_two(NULL, b, info, 2);
	info->flag = true;
	if (info->size == tmp_size)
	{
		while (tmp_size--)
			pa(b, a);
	}
}

void	ft_sort_a(t_list **a, t_list **b, t_info *info, int tmp_size)
{
	t_list	*nearest;

	(void)tmp_size;
	while (*a)
	{
		if (ft_lstsize(*b) >= 1)
			ft_sort_b(a, b, info, ft_lstsize(*b));
		check_sorted(a, info);
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
	}
	info->flag = true;
}
