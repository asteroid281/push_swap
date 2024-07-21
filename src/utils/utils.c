/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:43:48 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/20 20:57:33 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	get_node_to_top_a(t_node **stack_a, t_node *top_node)
{
	while (*stack_a != top_node)
	{
		if (top_node->is_above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	get_node_to_top_b(t_node **stack_b, t_node *top_node)
{
	while (*stack_b != top_node)
	{
		if (top_node->is_above_median)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void	lowest_node_on_top(t_node **stack_a)
{
	while (*stack_a != find_lowest_node(*stack_a))
	{
		if (find_lowest_node(*stack_a)->is_above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

long	ft_atol(const char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	if (ft_strlen(str) > 11)
		exit_with_error();
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	char_ptr_len(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}
