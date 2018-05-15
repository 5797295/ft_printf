/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:09:15 by jukim             #+#    #+#             */
/*   Updated: 2018/03/08 21:24:37 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copy at most len characters from src into dst.
** If src is less than len characters long, the remainder of dst
** is filled with `\0' characters.  Otherwise, dst is not terminated.
*/

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		else
			while (i < n)
				dst[i++] = '\0';
	}
	return (dst);
}
