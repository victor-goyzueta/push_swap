/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:18:45 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/27 21:56:13 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **src, t_list **dst)
{
	t_list	*node;

	if (!src || !*src)
		return ;
	node = *src;
	*src = node->next;
	node->next = *dst;
	*dst = node;
}
