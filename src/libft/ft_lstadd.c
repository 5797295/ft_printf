/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 20:51:05 by jukim             #+#    #+#             */
/*   Updated: 2018/03/10 22:27:54 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Adds the element new at the beginning of the list.
*/

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *list;

	list = *alst;
	new->next = list;
	*alst = new;
}
