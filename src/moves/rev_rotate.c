/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem < yunozdem@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:41:32 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/07 22:41:34 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rev_rotate(t_node **first_node)
{
	t_node	*last_node;

	if (!(*first_node) || !(*first_node)->next)
		return ;
	last_node = find_last_node(*first_node);
	last_node->prev->next = NULL;
	last_node->next = *first_node;
	last_node->prev = NULL;
	*first_node = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_node **a)
{
	rev_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node **b)
{
	rev_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
