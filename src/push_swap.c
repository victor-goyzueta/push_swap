/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:43:44 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/28 18:11:56 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_ordered(t_list **a, int *flag, int size)
{
	int		current;
	int		compared;
	t_list	*head;

	if (!a || !*a)
		return ;
	head = *a;
	if (*flag && size > 1)
	{
		current = *(int *)head->content;
		while (head->next)
		{
			head = head->next;
			compared = *(int *)head->content;
			if (current > compared)
				break ;
			current = *(int *)head->content;
			size--;
		}
	}
	if (!head->next && size == 1)
		exit(EXIT_SUCCESS);
	*flag = 0;
	return ;
}

void	size_two(t_list **a, t_list **b, int *flag, int size)
{
	if (size != 2)
		return ;
	ss(a, NULL);
	*flag = 1;
	push_swap(a, b, size);
}

void	size_three(t_list **a, t_list **b, int *flag, int size)
{
	if (size != 3)
		return ;
	//
	*flag = 1;
	push_swap(a, b, size);
}

void	push_swap(t_list **a, t_list **b, int size)
{
	static int	flag = 1;
	
	check_ordered(a, &flag, size);
	size_two(a, b, &flag, size);
	size_three(a, b, &flag, size);
}
