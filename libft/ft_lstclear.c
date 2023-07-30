/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:15:48 by tpinto-e          #+#    #+#             */
/*   Updated: 2022/12/07 18:12:24 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*helper;
	t_list	*extra;

	if (lst)
	{	
		helper = *lst;
		while (helper)
		{
			extra = helper->next;
			ft_lstdelone(helper, del);
			helper = extra;
		}
		*lst = NULL;
	}
}
