/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:12:23 by tpinto-e          #+#    #+#             */
/*   Updated: 2022/12/07 18:05:10 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*helper;

	if (!lst || !f || !f(lst->content))
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	new_list = NULL;
	while (lst)
	{
		helper = ft_lstnew(f(lst->content));
		if (!helper)
		{
			ft_lstclear(&helper, del);
			ft_lstclear(&lst, del);
			break ;
		}
		ft_lstadd_back(&new_list, helper);
		lst = lst->next;
	}
	return (new_list);
}
