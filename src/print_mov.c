/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:46:58 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/27 21:58:10 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **a, t_list **b)
{
	if (!b || !a)
	{
		if (!b)
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
	else
		ft_printf("ss\n");
}

void	pp(t_list **a, t_list **b)
{
	if (!b)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	rr(t_list **a, t_list **b)
{
	if (!b || !a)
	{
		if (!b)
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
	}
	else
		ft_printf("rr\n");
}

void	rrr(t_list **a, t_list **b)
{
	if (!b || !a)
	{
		if (!b)
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
	}
	else
		ft_printf("rrr\n");
}
