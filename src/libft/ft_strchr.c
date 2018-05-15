/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:47:00 by jukim             #+#    #+#             */
/*   Updated: 2018/03/08 18:58:14 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** searches for the first occurrence of the character c
** (an unsigned char) in the string pointed to by the argument str.
*/

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != (unsigned char)c)
		if (*str++ == '\0')
			return (NULL);
	return ((char *)str);
}
