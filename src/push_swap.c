/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:43:44 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/27 22:09:47 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_ordered(t_list **a, int *flag)
{
	int		current;
	int		compared;
	t_list	*head;

	head = *a;
	if (*flag == 0)
	{
		current = *(int *)head->content;
		while (head->next)
		{
			head = head->next;
			compared = *(int *)head->content;
			if (current > compared)
				break ;
			current = *(int *)head->content;
		}
		if (!head->next)
		{
			ft_printf("Niiice");
			exit(EXIT_SUCCESS);
		}
	}
	*flag = 1;
	return ;
}

void	push_swap(t_list **a, t_list **b)
{
	static int	flag = 0;

	(void)b;
	check_ordered(a, &flag);
}
