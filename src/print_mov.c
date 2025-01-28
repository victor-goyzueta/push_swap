/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:46:58 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/28 01:44:40 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **a, t_list **b)
{
	if (!b || !a)
	{
		if (!b)
		{
			swap(a);
			ft_printf("sa\n");
		}
		else
		{
			swap(b);
			ft_printf("sb\n");
		}
	}
	else
	{
		d_swap(a, b);
		ft_printf("ss\n");
	}
}

void	pp(t_list **a, t_list **b)
{
	if (!b)
	{
		push(b, a);
		ft_printf("pa\n");
	}
	else
	{
		push(a, b);
		ft_printf("pb\n");
	}
}

void	rr(t_list **a, t_list **b)
{
	if (!b || !a)
	{
		if (!b)
		{
			rotate(a);
			ft_printf("ra\n");
		}
		else
		{
			rotate(b);
			ft_printf("rb\n");
		}
	}
	else
	{
		d_rotate(a, b);
		ft_printf("rr\n");
	}
}

void	rrr(t_list **a, t_list **b)
{
	if (!b || !a)
	{
		if (!b)
		{
			reverse_rotate(a);
			ft_printf("rra\n");
		}
		else
		{
			reverse_rotate(b);
			ft_printf("rrb\n");
		}
	}
	else
	{
		d_reverse_rotate(a, b);
		ft_printf("rrr\n");
	}
}
