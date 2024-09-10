/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamgar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:41:05 by zamgar            #+#    #+#             */
/*   Updated: 2024/06/05 17:14:26 by zamgar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	newlst = (t_list *)malloc(sizeof(t_list));
	if (newlst == NULL)
		return (NULL);
	newlst->content = f(lst->content);
	newlst->next = NULL;
	temp = newlst;
	while (lst->next != NULL)
	{
		newlst->next = (t_list *)malloc(sizeof(t_list));
		if (newlst->next == NULL)
			return (NULL);
		newlst->next->content = f(lst->next->content);
		newlst->next->next = NULL;
		newlst = newlst->next;
		lst = lst->next;
	}
	return (temp);
}
