/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:40:30 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/20 20:46:33 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	space_skip(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] && argv[i] == ' ')
	{
		while (argv[i] == ' ')
			i++;
		if (argv[i] == '\0')
			exit_with_error();
	}
}

static void	validate_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		space_skip(argv[i]);
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && (j == 0 || argv[i][j
					- 1] == ' '))
			{
				if (argv[i][j + 1] == '\0' || !ft_isdigit(argv[i][j + 1]))
					exit_with_error();
				j++;
			}
			else if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ')
				exit_with_error();
			else
				j++;
		}
	}
}

static void	join_args(char **dest, int argc, char **argv)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		if (tmp2)
			free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	*dest = ft_strdup(tmp);
	if (*dest == NULL)
		exit_with_error();
	if (tmp)
		free(tmp);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	char	*joined;

	if (argc < 2)
		return (0);
	else if ((argc == 2 && !argv[1][0]))
		return (0);
	else
	{
		validate_arguments(argc, argv);
		joined = NULL;
		join_args(&joined, argc, argv);
		init_stack_a(&stack_a, joined);
		free(joined);
		if (stack_a && stack_sorted(stack_a) <= 0)
			sort_stack(&stack_a);
		free_stack(stack_a);
	}
	return (0);
}
