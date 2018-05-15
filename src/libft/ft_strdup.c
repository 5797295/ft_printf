/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 21:19:52 by jukim             #+#    #+#             */
/*   Updated: 2018/03/08 21:23:33 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocates sufficient memory for a copy of the string
** s1, does the copy, and returns a pointer to it.
*/

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char *copy;

	copy = malloc(ft_strlen(str1) + 1);
	if (copy != 0)
		ft_strcpy(copy, str1);
	return (copy);
}
