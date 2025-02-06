/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:59:58 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/06 16:38:28 by vgoyzuet         ###   ########.fr       */
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
}	t_info;

void	validate_arguments(int argc, char ***argv, char ***elements);
void	init_stack(t_list **a, char ***elements, t_info **info);
/*moves*/
void	swap(t_list **stack);
void	d_swap(t_list **a, t_list **b);
void	push(t_list **src, t_list **dst);
void	rotate(t_list **stack);
void	d_rotate(t_list **a, t_list **b);
void	reverse_rotate(t_list **stack);
void	d_reverse_rotate(t_list **a, t_list **b);
/*print moves*/
void	ss(t_list **a, t_list **b);
void	pa(t_list **b, t_list **a);
void	pb(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);
/*algorithm*/
void	push_swap(t_list **a, t_list **b, t_info *info);
void	size_three(t_list **a, t_info *info, int tmp_size);
void	size_short(t_list **a, t_list **b, t_info *info);
void	size_long(t_list **a, t_list **b, t_info *info);
void	worst_case_long(t_list **a, t_list **b, t_info *info, int tmp_size);
/*utils*/
void	check_success(t_list **a, t_info *info);
bool	is_sorted(t_list **increase, t_list **decrease);
t_list	*get_nearest(t_list **stack, t_info *info, int compared);

#endif
