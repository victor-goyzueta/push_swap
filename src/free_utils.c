/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:15:55 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/08 23:29:16 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **arr)
{
	int	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_list(t_list **stack)
{
	t_list	*tmp;

	tmp = NULL;
	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free((*stack)->content);
		free(*stack);
		*stack = tmp;
	}
}

void	free_info(t_info **info)
{
	if (!info || !*info)
		return ;
	free(*info);
}

void	free_all(t_list **stack, t_info **info, char **arr)
{
	free_list(stack);
	free_info(info);
	free_array(arr);
}

void	ft_exit_free(int EXIT, t_list **stack, t_info **info, char **arr)
{
	free_all(stack, info, arr);
	if (EXIT == EXIT_FAILURE)
		ft_perror(NULL);
	else
		exit(EXIT_SUCCESS);
}
