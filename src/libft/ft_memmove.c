/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:52:40 by jukim             #+#    #+#             */
/*   Updated: 2018/03/11 18:59:07 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copies len bytes from string src to string dst.  The two
** strings may overlap; the copy is always done in a non-destructive manner.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	i = -1;
	if (d < s)
		while (++i < n)
			d[i] = s[i];
	else
		while ((int)(--n) >= 0)
			d[n] = s[n];
	return (dst);
}
