/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:59:35 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/02/09 17:19:34 by vgoyzuet         ###   ########.fr       */
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
		if (!elements[0][i][j])
			ft_exit_free(EXIT_FAILURE, NULL, NULL, *elements);
		if (elements[0][i][j + 1] &&
			(elements[0][i][j] == '-' || elements[0][i][j] == '+'))
			j++;
		if (elements[0][i][j] == '0' &&
			(j != 0 || elements[0][i][j + 1] != '\0'))
			ft_exit_free(EXIT_FAILURE, NULL, NULL, *elements);
		while (ft_isdigit(elements[0][i][j]) && elements[0][i][j])
			j++;
		if (elements[0][i][j])
			ft_exit_free(EXIT_FAILURE, NULL, NULL, *elements);
		i++;
	}
}

static void	check_duplicated(char ***elements)
{
	int		i;
	int		j;
	long	current;
	long	compared;

	i = 0;
	while (elements[0][i])
	{
		j = i + 1;
		current = ft_atol(elements[0][i]);
		if (current > INT_MAX || current < INT_MIN)
			ft_exit_free(EXIT_FAILURE, NULL, NULL, *elements);
		while (elements[0][j])
		{
			compared = ft_atol(elements[0][j]);
			if (current == compared)
				ft_exit_free(EXIT_FAILURE, NULL, NULL, *elements);
			j++;
		}
		i++;
	}
}

static void	validate_arguments(int argc, char ***argv, char ***elements)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		*elements = ft_split(argv[0][1], ' ');
		if (!*elements)
			ft_exit_free(EXIT_FAILURE, NULL, NULL, *elements);
	}
	else if (argc > 2)
	{
		*elements = (char **)ft_calloc(argc, sizeof(char *));
		if (!*elements)
			ft_exit_free(EXIT_FAILURE, NULL, NULL, *elements);
		while (argv[0][i + 1])
		{
			elements[0][i] = ft_strdup(argv[0][i + 1]);
			if (!elements[0][i])
				ft_exit_free(EXIT_FAILURE, NULL, NULL, *elements);
			i++;
		}
		elements[0][i] = NULL;
	}
	else
		exit(EXIT_FAILURE);
}

void	push_swap(t_list **a, t_list **b, t_info *info)
{
	check_success(a, info);
	size_short(a, b, info);
	size_long(a, b, info);
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
	check_digit(&elements);
	check_duplicated(&elements);
	init_stack(&a, &elements, &info);
	ft_print_stack(a, "Stack A: \n");
	push_swap(&a, &b, info);
	ft_exit_free(EXIT_FAILURE, &a, &info, NULL);
}
