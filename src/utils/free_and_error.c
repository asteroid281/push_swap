/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem < yunozdem@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:43:19 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/07 22:43:20 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	exit_with_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}

void	free_input(char **input)
{
	int	i;

	i = -1;
	while (input[++i])
		free(input[i]);
	free(input);
}

void	free_stack(t_node *node)
{
	t_node	*temp;

	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}
