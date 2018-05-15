/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:08:28 by jukim             #+#    #+#             */
/*   Updated: 2018/03/10 22:30:52 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** interconnects strings
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = 0;
	j = 0;
	a = 0;
	while (dst[i])
		i++;
	while (src[j])
		j++;
	if (size > (i + 1))
	{
		while (a < (size - i - 1))
		{
			dst[i + a] = src[a];
			a++;
		}
		dst[i + a] = '\0';
	}
	if (i <= size)
		return (i + j);
	else
		return (size + j);
}
