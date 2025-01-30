/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:33:44 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/30 18:08:44 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_info(t_list **a, t_info **info)
{
	t_info	*node;

	node = (t_info *)malloc(sizeof(t_info));
	if (!node)
		ft_perror(NULL);
	node->size = ft_lstsize(*a);
	node->flag = true;
	*info = node;
	info = &node;
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
	init_info(a, info);
}
