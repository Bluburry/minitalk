/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:44:15 by tpinto-e          #+#    #+#             */
/*   Updated: 2022/12/05 19:04:01 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*helper;

	if (!*lst && new)
		*lst = new;
	else if (*lst && new)
	{
		helper = ft_lstlast(*lst);
		helper->next = new;
	}
}
