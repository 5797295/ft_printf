/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:13:20 by jukim             #+#    #+#             */
/*   Updated: 2018/03/08 20:24:37 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** locates the first occurrence of the null-terminated string str2 in
** the string str1, where not more than len characters are searched.
*/

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	char	*c;
	size_t	i;
	size_t	j;

	i = -1;
	c = (char*)str1;
	if (*str2 == '\0')
		return (c);
	while (c[++i] != '\0')
	{
		j = 0;
		while (str1[i + j] == str2[j] && i + j < n)
		{
			if (str2[j + 1] == '\0')
				return (&c[i]);
			++j;
		}
	}
	return (NULL);
}
