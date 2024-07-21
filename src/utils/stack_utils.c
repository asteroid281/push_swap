/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:16:39 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/20 20:57:59 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	stack_sorted(t_node *node)
{
	if (!node)
		return (-1);
	while (node->next)
	{
		if (node->nbr > node->next->nbr)
			return (0);
		node = node->next;
	}
	return (1);
}

int	get_stack_len(t_node *node)
{
	int	len;

	if (!node)
		return (0);
	len = 0;
	while (node)
	{
		node = node->next;
		len++;
	}
	return (len);
}

int	append_node(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*temp;

	node = malloc(sizeof(t_node));
	if (!node)
		return (-1);
	node->next = NULL;
	node->nbr = nbr;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		temp = find_last_node(*stack);
		temp->next = node;
		node->prev = temp;
	}
	return (0);
}

void	set_index_and_median(t_node *node)
{
	int	i;
	int	median;

	i = 0;
	if (!node)
		return ;
	if (get_stack_len(node) == 2)
		median = 0;
	else
		median = get_stack_len(node) / 2;
	while (node)
	{
		node->index = i;
		if (i <= median)
			node->is_above_median = 1;
		else
			node->is_above_median = 0;
		node = node->next;
		i++;
	}
}

void	init_stack_a(t_node **stack_a, char *joined)
{
	char	**tmp;
	long	nbr;
	int		i;

	tmp = ft_split(joined, ' ');
	i = 0;
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		nbr = ft_atol(tmp[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			free_stack(*stack_a);
			exit_with_error();
		}
		append_node(stack_a, (int)nbr);
		check_duplicate(stack_a);
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
