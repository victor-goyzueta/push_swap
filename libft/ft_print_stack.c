/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:16:41 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/05 23:42:03 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_stack(t_list *stack, char *str)
{
	t_list	*current;

	ft_printf("%s\n", str);
	if (!stack)
	{
		ft_printf("empty\n");
		return ;
	}
	current = stack;
	while (current)
	{
		ft_printf("[%d]%d\n", current->i, *(int *)current->content);
		current = current->next;
	}
}
