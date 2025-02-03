/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:21:15 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/03 02:06:30 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	first_checks(t_list **a, t_list **b, t_info *info, t_list *smaller)
{
	if (*(int *)(*a)->content == info->biggest)
		rr(a, NULL);
	else if (info->smallest == *(int *)(*a)->content || smaller == *a)
		pb(a, b);
	else if (smaller == (*a)->next)
		ss(a, NULL);
	else
		rrr(a, NULL);
	size_any(a, b, info, ft_lstsize(*a));
}

static void	second_checks(t_list **a, t_list **b, t_info *info)
{
	//
}

static void	third_checks(t_list **a, t_list **b, t_info *info)
{
	size_three(a, info, 3);
	while (ft_lstsize(*b))
	{
		if (*b && !is_sorted(NULL, b))
			ss(NULL, b);
		pa(b, a);
		if (*a && !is_sorted(a, NULL))
			ss(a, NULL);
	}
}

// static void	check_doble_moves(t_list **a, t_list **b, t_info *info)
// {
// 	//
// }

void	size_any(t_list **a, t_list **b, t_info *info, int tmp_size)
{
	t_list	*smaller;

	smaller = get_nearest(a, info, info->smallest);
	check_success(a, info);
	if (tmp_size > 3 && ft_lstsize(*b) < 2)
		first_checks(a, b, info, smaller);
	else
		third_checks(a, b, info);
}
