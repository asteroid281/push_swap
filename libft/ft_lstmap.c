/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunozdem <yunozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:11:25 by yunozdem          #+#    #+#             */
/*   Updated: 2024/07/13 14:27:02 by yunozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*changed;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		temp = f(lst->content);
		if (!temp)
			return (ft_lstclear(&res, del), NULL);
		changed = ft_lstnew(temp);
		if (!changed)
			return (ft_lstclear(&res, del), del(temp), NULL);
		ft_lstadd_back(&res, changed);
		lst = lst->next;
	}
	return (res);
}
