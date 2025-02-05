/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:35:43 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/06 00:22:25 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_range(int	size)
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
		if ((*a)->index <= i)
		{
			pb(a, b);
			rr(NULL, b);
			i++;
		}
		else if ((*a)->index > i && (*a)->index <= (i + range))
		{
			pb(a, b);
			i++;
		}
		else
			rr(a, NULL);
	}
}

// static void	sort_second(t_list **a, t_list **b, t_info *info)
// {
// 	//
// }

void	size_long(t_list **a, t_list **b, t_info *info)
{
	sort_first(a, b, info);
//	sort_second(a, b, info);
}
