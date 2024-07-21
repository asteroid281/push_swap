/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem < yunozdem@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:43:03 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/08 00:19:57 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_node	*find_last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_node	*find_biggest_node(t_node *node)
{
	t_node	*biggest_node;
	long	biggest_value;

	if (!node)
		return (NULL);
	biggest_value = LONG_MIN;
	while (node)
	{
		if (node->nbr > biggest_value)
		{
			biggest_value = node->nbr;
			biggest_node = node;
		}
		node = node->next;
	}
	return (biggest_node);
}

t_node	*find_lowest_node(t_node *node)
{
	t_node	*lowest_node;
	long	lowest_value;

	if (!node)
		return (NULL);
	lowest_value = LONG_MAX;
	while (node)
	{
		if (node->nbr < lowest_value)
		{
			lowest_value = node->nbr;
			lowest_node = node;
		}
		node = node->next;
	}
	return (lowest_node);
}
