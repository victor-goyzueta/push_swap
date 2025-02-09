/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:02:24 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/09 03:40:31 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft.h"
# include "stdbool.h"

void	init(t_list **a, char ***elements);
void	checker(t_list **a, t_list **b);
/*utils*/
void	check_success(t_list **a, int size);
/*moves*/
void	swap(t_list **stack);
void	d_swap(t_list **a, t_list **b);
void	push(t_list **src, t_list **dst);
void	rotate(t_list **stack);
void	d_rotate(t_list **a, t_list **b);
void	reverse_rotate(t_list **stack);
void	d_reverse_rotate(t_list **a, t_list **b);
/*free*/
void	free_array(char **arr);
void	free_list(t_list **stack);
void	free_all(t_list **stack, char **arr);
void	ft_exit_free(int EXIT, t_list **stack, char **arr, bool check);

#endif
