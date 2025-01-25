/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:59:35 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/25 18:16:50 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(char ***elements)
{
	int	i;
	int	j;

	i = 0;
	while (elements[0][i])
	{
		j = 0;
		if (elements[0][i][j] == '-' || elements[0][i][j] == '+')
			j++;
		while (ft_isdigit(elements[0][i][j]) && elements[0][i][j])
			j++;
		if (elements[0][i][j])
			exit(EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (elements[0][i])
	{
		j = i + 1;
		while (elements[0][j] && (ft_strcmp(elements[0][i], elements[0][j]) != 0))
			j++;
		if (elements[0][j])
			ft_perror("Duplicated elements");
		i++;
	}
}

void free_elements(char **elements)
{
	int i;

	i = 0;
	if (!elements)
		return ;
	while (elements[i])
	{
		free(elements[i]);
		i++;
	}
	free(elements);
}

char	**validate_arguments(int argc, char ***argv)
{
	char	**elements = NULL;
	int		i;

	i = 0;
	if (argc == 2)
	{
		elements = ft_split(argv[0][1], ' ');
		if (!elements)
			ft_perror("Memory allocation failed");
	}
	else if (argc > 2)
	{
		elements = (char **)malloc(sizeof(char *) * argc);
		if (!elements)
			ft_perror("Memory allocation failed");
		while (argv[0][i + 1])
		{
			elements[i] = argv[0][i + 1];
			i++;
		}
		elements[i] = NULL;
	}
	else
		exit(EXIT_FAILURE);
	parsing(&elements);
	return (elements);
}

void	init_stack(t_list **a, char ***elements)
{
	int		i;
	int		*content;
	t_list	*node;

	i = 0;
	while (elements[0][i])
	{
		content = (int *)malloc(sizeof(int));
		if (!content)
			ft_perror("Memory allocation failed");		
		*content = ft_atol(elements[0][i]);
		node = ft_lstnew(content);
		if (!node)
			ft_perror("Memory allocation failded");
		ft_lstadd_back(a, node);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a = NULL;
	t_list	*node;
	char	**elements;

	elements = validate_arguments(argc, &argv);
	init_stack(&a, &elements);
	node = a;
	while (node)
	{
		ft_printf("%d\n", *(int *)(node->content));
		node = node->next;
	}
	return (0);
}
