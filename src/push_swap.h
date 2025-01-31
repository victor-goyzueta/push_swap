/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:59:58 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/31 14:25:15 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_info
{
	int		size;
	int		smallest;
	int		biggest;
	bool	flag;
}	t_info;

void	validate_arguments(int argc, char ***argv, char ***elements);
void	init_stack(t_list **a, char ***elements, t_info **info);
void	swap(t_list **stack);
void	d_swap(t_list **a, t_list **b);
void	push(t_list **src, t_list **dst);
void	rotate(t_list **stack);
void	d_rotate(t_list **a, t_list **b);
void	reverse_rotate(t_list **stack);
void	d_reverse_rotate(t_list **a, t_list **b);
void	push_swap(t_list **a, t_list **b, t_info *info, int	tmp_size);
void	check_sorted(t_list **a, t_info *info);
void	size_two(t_list **a, t_list **b, t_info *info, int tmp_size);
void	size_three(t_list **a, t_list **b, t_info *info, int tmp_size);
void	ft_sort_a(t_list **a, t_list **b, t_info *info, int tmp_size);
//funtion to sort decre
//funtion to sort ascen
//funtion to check doble moves
/* Evitar Recursivos en casos pequeños*/

void	ss(t_list **a, t_list **b);
void	pa(t_list **b, t_list **a);
void	pb(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);

#endif
