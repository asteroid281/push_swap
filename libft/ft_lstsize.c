/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem < yunozdem@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:12:10 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/08 00:18:06 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counted;

	if (!lst)
		return (0);
	counted = 0;
	while (lst->next)
	{
		counted++;
		lst = lst->next;
	}
	return (counted + 1);
}
