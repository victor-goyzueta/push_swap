/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:34:15 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/09 04:10:43 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	free_all(t_list **stack, char **arr)
{
	free_list(stack);
	free_array(arr);
}

void	ft_exit_free(int EXIT, t_list **stack, char **arr, bool check)
{
	free_all(stack, arr);
	if (EXIT == EXIT_FAILURE)
		ft_perror(NULL);
	else if (check)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	exit(EXIT);
}

void	check_success(t_list **a, int size)
{
	int		current;
	int		compared;
	bool	check;
	t_list	*head;

	if (!a || !*a)
		return ;
	check = false;
	head = *a;
	if (size > 1)
	{
		current = *(int *)head->content;
		while (head->next)
		{
			head = head->next;
			compared = *(int *)head->content;
			if (current > compared)
				break ;
			current = *(int *)head->content;
			size--;
		}
	}
	if (!head->next && size == 1)
		check = true;
	ft_exit_free(EXIT_SUCCESS, a, NULL, check);
}
