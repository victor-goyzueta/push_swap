/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:33:44 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/06 00:20:06 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_smallest(t_list **a)
{
	t_list	*head;
	int		compared;
	int		smallest;

	head = *a;
	smallest = *(int *)head->content;
	while (head->next)
	{
		compared = *(int *)head->next->content;
		if (compared < smallest)
			smallest = compared;
		head = head->next;
	}
	return (smallest);
}

static int	get_biggest(t_list **a)
{
	t_list	*head;
	int		compared;
	int		biggest;

	head = *a;
	biggest = *(int *)head->content;
	while (head->next)
	{
		compared = *(int *)head->next->content;
		if (compared > biggest)
			biggest = compared;
		head = head->next;
	}
	return (biggest);
}

static void	init_info(t_list **a, t_info **info)
{
	t_info	*node;

	node = (t_info *)malloc(sizeof(t_info));
	if (!node)
		ft_perror(NULL);
	node->size = ft_lstsize(*a);
	node->smallest = get_smallest(a);
	node->biggest = get_biggest(a);
	*info = node;
	info = &node;
}

static void	get_index(t_list **a)
{
	t_list	*current;
	t_list	*compared;

	if (!a || !*a)
		return ;
	current = *a;
	while (current->next)
	{
		compared = current->next;
		while (compared)
		{
			if (*(int *)current->content < *(int *)compared->content)
				compared->index += 1;
			else
				current->index += 1;
			compared = compared->next;
		}
		current = current->next;
	}
}

void	init_stack(t_list **a, char ***elements, t_info **info)
{
	int		i;
	int		*content;
	t_list	*node;

	i = 0;
	while (elements[0][i])
	{
		content = (int *)malloc(sizeof(int));
		if (!content)
			ft_perror(NULL);
		*content = ft_atol(elements[0][i]);
		node = ft_lstnew(content);
		if (!node)
			ft_perror(NULL);
		ft_lstadd_back(a, node);
		i++;
	}
	get_index(a);
	init_info(a, info);
}
