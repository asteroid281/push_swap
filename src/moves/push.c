/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:41:08 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/17 17:15:29 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	push(t_node **dst, t_node **src)
{
	t_node	*temp;

	if (!(*src))
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->prev = NULL;
	if (!*dst)
	{
		*dst = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *dst;
		temp->next->prev = temp;
		*dst = temp;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
