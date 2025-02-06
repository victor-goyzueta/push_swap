/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:43:44 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/06 16:38:12 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_doble_moves(t_list **a, t_list **b, t_info *info)
{
	t_list	*smaller_a;
	t_list	*bigger_a;
	t_list	*smaller_b;
	t_list	*bigger_b;

	if (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2)
		return ;
	while (1)
	{
		smaller_a = get_nearest(a, info, info->smallest);
		bigger_a = get_nearest(a, info, info->biggest);
		smaller_b = get_nearest(b, info, info->smallest);
		bigger_b = get_nearest(b, info, info->biggest);
		check_success(a, info);
		if (((*a)->next == smaller_a) && ((*b)->next == bigger_b))
			ss(a, b);
		else if (*a == bigger_a && *b == smaller_b)
			rr(a, b);
		else if (ft_lstlast(*a) == smaller_a && ft_lstlast(*b) == bigger_b)
			rrr(a, b);
		else
			break ;
	}
	check_success(a, info);
}

static void	size_two(t_list **a, t_info *info)
{
	if (info->size == 2 && !is_sorted(a, NULL))
		ss(a, NULL);
}

void	size_three(t_list **a, t_info *info, int tmp_size)
{
	t_list	*smallest;
	t_list	*biggest;

	if (tmp_size == 3 && !is_sorted(a, NULL))
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
		else if (*a == biggest && ft_lstlast(*a) != smallest)
			rr(a, NULL);
		else if (ft_lstlast(*a) == biggest)
			ss(a, NULL);
		else
			rrr(a, NULL);
	}
}

static void	size_five(t_list **a, t_list **b, t_info *info)
{
	t_list	*smallest;

	while (ft_lstsize(*a) > 3)
	{
		smallest = get_nearest(a, info, info->smallest);

		if (*a == smallest)
			pb(a, b);
		else if ((*a)->next == smallest)
			ss(a, NULL);
		else
			rrr(a, NULL);
	}
	check_doble_moves(a, b, info);
	size_three(a, info, 3);
	while (ft_lstsize(*b))
	{
		pa(b, a);
		if (*(int *)(*a)->content > *(int *)(*a)->next->content)
			ss(a, NULL);
	}
}

void	size_short(t_list **a, t_list **b, t_info *info)
{
	if (info->size > 5)
		return ;
	size_two(a, info);
	size_three(a, info, info->size);
	size_five(a, b, info);
	check_success(a, info);
}
