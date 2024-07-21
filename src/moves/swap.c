/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem < yunozdem@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:42:11 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/09 16:11:04 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	swap(t_node **first_node)
{
	if (!(*first_node) || !(*first_node)->next)
		return ;
	*first_node = (*first_node)->next;
	(*first_node)->prev->prev = *first_node;
	(*first_node)->prev->next = (*first_node)->next;
	if ((*first_node)->next)
		(*first_node)->next->prev = (*first_node)->prev;
	(*first_node)->next = (*first_node)->prev;
	(*first_node)->prev = NULL;
}

void	sa(t_node **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
