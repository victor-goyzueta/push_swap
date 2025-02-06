/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:35:43 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/06 19:20:48 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_range(int size)
{
	int	result;

	result = 1;
	if (size < 0)
		return (0);
	while ((result * result) <= size)
	{
		if ((result * result) == size)
			return (result * (140 / 100));
		result++;
	}
	result--;
	return (result * (140 / 100));
}

static void	sort_first(t_list **a, t_list **b, t_info *info)
{
	int	i;
	int	range;

	i = 0;
	range = get_range(info->size);
	while (ft_lstsize(*a))
	{
		if (*(int *)(*a)->content <= i)
		{
			pb(a, b);
			if (ft_lstsize(*b) > 1)
				rr(NULL, b);
			i++;
		}
		else if (*(int *)(*a)->content > i &&
			*(int *)(*a)->content <= (i + range))
		{
			pb(a, b);
			i++;
		}
		else
			rr(a, NULL);
	}
}

static int	counter(t_list **b, int size)
{
	int		i;
	t_list	*node;

	i = 0;
	node = *b;
	while (node && (node)->index != size)
	{
		node = (*node).next;
		i++;
	}
	return (i);
}

static void	sort_second(t_list **a, t_list **b, t_info *info)
{
	int	rotates;
	int	i;

	i = (info->size - 1);
	while (ft_lstsize(*b))
	{
		rotates = counter(b, i);
		if (rotates <= (ft_lstsize(*b) / 2))
		{
			while ((*b)->index != i)
				rr(NULL, b);
			pa(b, a);
			i--;
		}
		else
		{
			while ((*b)->index != i)
				rrr(NULL, b);
			pa(b, a);
			i--;
		}
	}
}

void	size_long(t_list **a, t_list **b, t_info *info)
{
	if (is_sorted(NULL, a))
		worst_case_long(a, b, info, info->size);
	sort_first(a, b, info);
	sort_second(a, b, info);
	check_success(a, info);
}
