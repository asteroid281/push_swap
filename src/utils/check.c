/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:42:40 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/14 04:38:35 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	check_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

void	check_duplicate(t_node **stack_a)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (!stack_a)
		return ;
	tmp1 = *stack_a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->nbr == tmp2->nbr)
			{
				free_stack(*stack_a);
				exit_with_error();
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
