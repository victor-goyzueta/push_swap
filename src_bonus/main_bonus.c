/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:04:49 by vgoyzuet          #+#    #+#             */
/*   Updated: 2025/08/11 23:05:54 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	check_digit(char ***elements)
{
	int	i;
	int	j;

	i = 0;
	while (elements[0][i])
	{
		j = 0;
		if (!elements[0][i][j])
			ft_exit_free(EXIT_FAILURE, NULL, *elements, false);
		if (elements[0][i][j + 1] &&
			(elements[0][i][j] == '-' || elements[0][i][j] == '+'))
			j++;
		if (elements[0][i][j] == '0' &&
			(j != 0 || elements[0][i][j + 1] != '\0'))
			ft_exit_free(EXIT_FAILURE, NULL, *elements, false);
		while (ft_isdigit(elements[0][i][j]) && elements[0][i][j])
			j++;
		if (elements[0][i][j])
			ft_exit_free(EXIT_FAILURE, NULL, *elements, false);
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
			ft_exit_free(EXIT_FAILURE, NULL, *elements, false);
		while (elements[0][j])
		{
			compared = ft_atol(elements[0][j]);
			if (current == compared)
				ft_exit_free(EXIT_FAILURE, NULL, *elements, false);
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
			ft_exit_free(EXIT_FAILURE, NULL, *elements, false);
	}
	else if (argc > 2)
	{
		*elements = (char **)ft_calloc(argc, sizeof(char *));
		if (!*elements)
			ft_exit_free(EXIT_FAILURE, NULL, *elements, false);
		while (argv[0][i + 1])
		{
			elements[0][i] = ft_strdup(argv[0][i + 1]);
			if (!elements[0][i])
				ft_exit_free(EXIT_FAILURE, NULL, *elements, false);
			i++;
		}
		elements[0][i] = NULL;
	}
	else
		exit(EXIT_FAILURE);
}

void	init(t_list **a, char ***elements)
{
	int		i;
	int		*content;
	t_list	*node;

	i = 0;
	while (elements[0][i])
	{
		content = (int *)ft_calloc(1, sizeof(int));
		if (!content)
			ft_exit_free(EXIT_FAILURE, a, *elements, false);
		*content = ft_atoi(elements[0][i]);
		node = ft_lstnew(content);
		if (!node)
			ft_exit_free(EXIT_FAILURE, a, *elements, false);
		ft_lstadd_back(a, node);
		i++;
	}
	free_array(*elements);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**elements;

	a = NULL;
	b = NULL;
	validate_arguments(argc, &argv, &elements);
	check_digit(&elements);
	check_duplicated(&elements);
	init(&a, &elements);
	checker(&a, &b);
}
