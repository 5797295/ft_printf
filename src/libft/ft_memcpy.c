/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 15:46:53 by jukim             #+#    #+#             */
/*   Updated: 2018/05/09 22:35:01 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copies n bytes from memory area src to memory area dst.  If dst and src
** overlap, behavior is undefined.
*/

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = (const char *)src;
	d = (char *)dst;
	while (n-- != 0)
		*d++ = *s++;
	return (dst);
}
