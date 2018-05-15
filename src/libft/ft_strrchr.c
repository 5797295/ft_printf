/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:58:26 by jukim             #+#    #+#             */
/*   Updated: 2018/03/10 22:16:40 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** searches for the last occurrence of the character c
** (an unsigned char) in the string pointed to, by the argument str.
*/

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		--i;
	}
	return (NULL);
}
