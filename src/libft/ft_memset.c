/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:28:36 by jukim             #+#    #+#             */
/*   Updated: 2018/03/10 21:43:03 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** fills the first n bytes of the memory area
** pointed to by s with the constant byte c.
*/

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *s;

	s = str;
	while (n-- != 0)
		*s++ = (unsigned char)c;
	return (str);
}
