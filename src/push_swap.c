/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:43:44 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/02 20:55:57 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_two(t_list **a, t_list **b, t_info *info, int tmp_size)
{
	(void)info;
	if (tmp_size == 2)
	{
		if (!b || !a)
		{
			if (!b)
				ss(a, NULL);
			else
				ss(NULL, b);
		}
		else
			ss(a, b);
	}
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
		else if (*a == biggest&& ft_lstlast(*a) != smallest)
			rr(a, NULL);
		else if (ft_lstlast(*a) == biggest)
			ss(a, NULL);
		else
			rrr(a, NULL);
	}
}

void	size_five(t_list **a, t_list **b, t_info *info, int tmp_size)
{
	t_list	*smaller;

	smaller = get_nearest(a, info, info->smallest);
	check_success(a, info);
	if (tmp_size > 3 && ft_lstsize(*b) < 2)
	{
		if (*(int *)(*a)->content == info->biggest)
			rr(a, NULL);
		else if (info->smallest == *(int *)(*a)->content || smaller == *a)
			pb(a, b);
		else if (smaller == (*a)->next)
			ss(a, NULL);
		else
			rrr(a, NULL);
		size_five(a, b, info, ft_lstsize(*a));
	}
	else
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
}

void	push_swap(t_list **a, t_list **b, t_info *info, int	tmp_size)
{
	(void)tmp_size;
	check_success(a, info);
	size_two(a, b, info, info->size);
	size_three(a, info, info->size);
	size_five(a, b, info, info->size);
	check_success(a, info);
}
