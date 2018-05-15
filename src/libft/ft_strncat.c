/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 21:25:44 by jukim             #+#    #+#             */
/*   Updated: 2018/03/10 22:07:36 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** adds the string pointed to by src to the end of the string
** pointed to by dest up to n characters long.
*/

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char *str;

	str = dst;
	while (*dst)
		dst++;
	while (n-- != 0 && (*dst++ = *src++))
		if (n == 0)
			*dst = '\0';
	return (str);
}
