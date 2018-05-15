/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 20:51:42 by jukim             #+#    #+#             */
/*   Updated: 2018/03/10 22:29:32 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Iterates a list lst and applies the function f to each link to
** create a “fresh” list (using malloc(3)) resulting from the successive
** applications of f. If the allocation fails, the function
** returns NULL.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*list;
	t_list	*tmp;

	if (!(head = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	tmp = NULL;
	while (lst)
	{
		list = f(lst);
		if (tmp)
			tmp->next = list;
		else
			head = list;
		tmp = list;
		lst = lst->next;
	}
	return (head);
}
