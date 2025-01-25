/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:59:35 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/25 08:52:53 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(char **elements)
{
	int	i;
	int	j;

	i = 0;
	while (elements[i])
	{
		j = 0;
		if (elements[i][j] == '-' || elements[i][j] == '+')
			j++;
		while (ft_isdigit(elements[i][j]) && elements[i][j])
			j++;
		if (elements[i][j])
			exit(EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (elements[i])
	{
		j = i + 1;
		while (elements[j] && (ft_strcmp(elements[i], elements[j]) != 0))
			j++;
		if (elements[j])
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

void	validate_arguments(int argc, char **argv)
{
	char	**elements = NULL;
	int		i;

	i = 0;
	if (argc == 2)
	{
		elements = ft_split(argv[1], ' ');
		if (!elements)
			ft_perror("Memory allocation failed");
	}
	else if (argc > 2)
	{
		elements = (char **)malloc(sizeof(char *) * argc);
		if (!elements)
			ft_perror("Memory allocation failed");
		while (argv[i + 1])
		{
			elements[i] = argv[i + 1];
			i++;
		}
		elements[i] = NULL;
	}
	parsing(elements);
	if (argc == 2)
		free_elements(elements);
}

void	init_stack(t_list **a, char **argv)
{
	int		i;
	int		*content;
	t_list	*node;

	i = 1;
	while (argv[i])
	{
		content = (int *)malloc(sizeof(int));
		if (!content)
			ft_perror("Memory allocation failed");		
		*content = ft_atol(argv[i]);
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

	validate_arguments(argc, argv);
	init_stack(&a, argv);
	node = a;
	while (node)
	{
		ft_printf("%d\n", *(int *)(node->content));
		node = node->next;
	}
	return (0);
}

/*
./push_swap 1 2 3 4 5
1
2
3
4
5
./push_swap "1 2 3 4 5"
1						(¿Qué pasa?)
*/