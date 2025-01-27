/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:59:58 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/27 00:24:53 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

void	validate_arguments(int argc, char ***argv, char ***elements);
void	init_stack(t_list **a, char ***elements);
void	swap(t_list **stack);
void	d_swap(t_list **a, t_list **b);
void	push(t_list **src, t_list **dst);
void	rotate(t_list **stack);
void	d_rotate(t_list **a, t_list **b);
void	reverse_rotete(t_list **stack);
void	d_reverse_rotete(t_list **a, t_list **b);

void	print_stack(t_list *stack, char *str);

#endif
