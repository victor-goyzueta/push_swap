/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:59:35 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/01/30 18:09:37 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_digit(char ***elements)
{
	int	i;
	int	j;

	i = 0;
	while (elements[0][i])
	{
		j = 0;
		if (elements[0][i][j + 1] &&
			(elements[0][i][j] == '-' || elements[0][i][j] == '+'))
			j++;
		if (elements[0][i][j] == '0' &&
			(j != 0 || elements[0][i][j + 1] != '\0'))
			ft_perror(NULL);
		while (ft_isdigit(elements[0][i][j]) && elements[0][i][j])
			j++;
		if (elements[0][i][j])
			ft_perror(NULL);
		i++;
	}
}

static void	check_duplicated(char ***elements)
{
	int	i;
	int	j;
	int	current;
	int	compared;

	i = 0;
	while (elements[0][i])
	{
		j = i + 1;
		current = ft_atol(elements[0][i]);
		while (elements[0][j])
		{
			compared = ft_atol(elements[0][j]);
			if (current == compared)
				ft_perror(NULL);
			j++;
		}
		i++;
	}
}

void	validate_arguments(int argc, char ***argv, char ***elements)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		*elements = ft_split(argv[0][1], ' ');
		if (!*elements)
			ft_perror(NULL);
	}
	else if (argc > 2)
	{
		*elements = (char **)malloc(sizeof(char *) * argc);
		if (!elements)
			ft_perror(NULL);
		while (argv[0][i + 1])
		{
			elements[0][i] = argv[0][i + 1];
			i++;
		}
		elements[0][i] = NULL;
	}
	else
		exit(EXIT_FAILURE);
	check_digit(elements);
	check_duplicated(elements);
}

void	init_stack_info(t_list **a, char ***elements, t_info **info)
{
	int		i;
	int		*content;
	t_list	*node;
	t_info	*n_info;

	i = 0;
	while (elements[0][i])
	{
		content = (int *)malloc(sizeof(int));
		if (!content)
			ft_perror(NULL);
		*content = ft_atol(elements[0][i]);
		node = ft_lstnew(content);
		if (!node)
			ft_perror(NULL);
		ft_lstadd_back(a, node);
		i++;
	}
	n_info = (t_info *)malloc(sizeof(t_info));
	if (!n_info)
		ft_perror(NULL);
	n_info->size = ft_lstsize(*a);
	n_info->flag = true;
	*info = n_info;
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_info	*info;
	char	**elements;

	a = NULL;
	b = NULL;
	info = NULL;
	validate_arguments(argc, &argv, &elements);
	init_stack(&a, &elements, &info);
	/*test*/
	ft_print_stack(a, "Stack A:");
	ft_print_stack(b, "Stack B:");
	ft_printf("\n");
	push_swap(&a, &b, info);
	ft_print_stack(a, "Stack A:");
	return (0);
}
