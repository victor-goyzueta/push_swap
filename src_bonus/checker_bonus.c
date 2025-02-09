/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 02:18:21 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/09 04:28:25 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	make_moves(t_list **a, t_list **b, char *move)
{
	if (ft_strcmp(move, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(move, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(move, "ss\n") == 0)
		d_swap(a, b);
	else if (ft_strcmp(move, "pa\n") == 0)
		push(b, a);
	else if (ft_strcmp(move, "pb\n") == 0)
		push(a, b);
	else if (ft_strcmp(move, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(move, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(move, "rr\n") == 0)
		d_rotate(a, b);
	else if (ft_strcmp(move, "rra\n") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(move, "rrb\n") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(move, "rrr\n") == 0)
		d_reverse_rotate(a, b);
}

void	checker(t_list **a, t_list **b)
{
	int		size;
	char	*move;

	size = ft_lstsize(*a);
	move = NULL;
	move = get_next_line(0);
	while (move)
	{
		make_moves(a, b, move);
		free(move);
		move = get_next_line(0);
	}
	free(move);
	check_success(a, size);
}
