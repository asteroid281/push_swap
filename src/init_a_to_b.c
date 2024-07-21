/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:37:47 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/14 00:56:22 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_targets_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*node_b;
	t_node	*target_node;
	long	closest_smaller_nbr;

	while (stack_a)
	{
		closest_smaller_nbr = LONG_MIN;
		node_b = stack_b;
		while (node_b)
		{
			if (node_b->nbr < stack_a->nbr && node_b->nbr > closest_smaller_nbr)
			{
				closest_smaller_nbr = node_b->nbr;
				target_node = node_b;
			}
			node_b = node_b->next;
		}
		if (closest_smaller_nbr == LONG_MIN)
			stack_a->target = find_biggest_node(stack_b);
		else
			stack_a->target = target_node;
		stack_a = stack_a->next;
	}
}

void	calculate_costs(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = get_stack_len(stack_a);
	len_b = get_stack_len(stack_b);
	while (stack_a)
	{
		stack_a->cost = stack_a->index;
		if (!(stack_a->is_above_median))
			stack_a->cost = len_a - (stack_a->index);
		if (stack_a->target->is_above_median)
			stack_a->cost += stack_a->target->index;
		else
			stack_a->cost += len_b - (stack_a->target->index);
		stack_a = stack_a->next;
	}
}

t_node	*get_cheapest_node(t_node *stack_a, t_node *stack_b)
{
	t_node	*cheapest_node;
	long	cheapest_value;

	if (!stack_a)
		return (NULL);
	cheapest_value = LONG_MAX;
	calculate_costs(stack_a, stack_b);
	while (stack_a)
	{
		if (stack_a->cost < cheapest_value)
		{
			cheapest_value = stack_a->cost;
			cheapest_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (cheapest_node);
}

void	init_nodes_a(t_node *a, t_node *b)
{
	set_index_and_median(a);
	set_index_and_median(b);
	set_targets_a(a, b);
}
