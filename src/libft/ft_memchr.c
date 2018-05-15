/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:52:49 by jukim             #+#    #+#             */
/*   Updated: 2018/03/10 22:06:34 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** searches for the first occurrence of the character c (an unsigned char)
** in the first n bytes of the string pointed to, by the argument str.
*/

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char *s;

	s = (unsigned char *)str;
	while (n-- != 0)
	{
		if (*s == (unsigned char)c)
			return (s);
		s++;
	}
	return (NULL);
}
