/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:53:07 by jukim             #+#    #+#             */
/*   Updated: 2018/03/10 22:03:07 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** adds the string pointed to by src to the
** end of the string pointed to by dest.
*/

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	char *str;

	str = dst;
	while (*dst)
		dst++;
	while ((*dst++ = *src++))
		;
	return (str);
}
