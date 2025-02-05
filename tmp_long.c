/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:21:15 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/05 20:55:01 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	first_checks(t_list **a, t_list **b, t_info *info)
{
	t_list	*smaller;
	t_list	*bigger;

	if (is_sorted(a, NULL) && is_sorted(NULL, b))
		return ;
	while (ft_lstsize (*a) > 2 && ft_lstsize(*b) > 1)
	{
		smaller = get_nearest(b, info, info->smallest);
		bigger = get_nearest(b, info, info->biggest);
		if (*b == smaller)
			rr(NULL, b);
		else if (*b != bigger)
			ss(NULL, b);
		else if (is_sorted(a, NULL) && is_sorted(NULL, b))
			pa(b, a);
		else
			break ;
	}
}

static void	second_checks(t_list **a, t_list **b, t_info *info)
{
	t_list		*smaller;
	static int	count;

	smaller = get_nearest(a, info, info->smallest);
	if (ft_lstsize(*a) < 4 || (is_sorted(a, NULL) &&
		(ft_lstsize(*b) > 2 && is_sorted(NULL, b) &&
		(abs(*(int *)(*a)->content - info->smallest) >
		abs(*(int *)(*b)->content - info->smallest)))))
		return ;
	if (*(int *)(*a)->content == info->biggest)
		rr(a, NULL);
	else if (smaller == *a)
	{
		if (is_sorted(a, NULL))
		{
			pa(b, a);
			size_long(a, b, info, ft_lstsize(*a));
		}
		pb(a, b);
	}
	else if (smaller == (*a)->next)
		ss(a, NULL);
	else
		rrr(a, NULL);
	size_long(a, b, info, ft_lstsize(*a));
}

static void	third_checks(t_list **a, t_list **b, t_info *info)
{
	size_three(a, info, 3);
	while (ft_lstsize(*b))
	{
		if (ft_lstsize(*b) > 3 && (abs((*(int *)(*b)->next->content) - info->smallest) 
			< abs((*(int *)(*b)->next->content - info->biggest))))
		{
			pa(b, a);
			size_long(a, b, info, ft_lstsize(*a));//
		}
		else if ((*b)->next && !is_sorted(NULL, b))
			ss(NULL, b);
		pa(b, a);
		if (*a && !is_sorted(a, NULL))
			ss(a, NULL);
	}
}

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
		if (((*a)->next == smaller_a && (*b)->next == bigger_b)
			&& (*a != bigger_a && *b != smaller_b))
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

void	size_long(t_list **a, t_list **b, t_info *info, int tmp_size)
{
	(void)tmp_size;
	check_success(a, info);
	check_doble_moves(a, b, info);
	first_checks(a, b, info);
	second_checks(a, b, info);
	third_checks(a, b, info);
	check_success(a, info);
}
