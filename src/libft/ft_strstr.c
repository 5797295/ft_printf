/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:04:57 by jukim             #+#    #+#             */
/*   Updated: 2018/03/08 20:23:20 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** finds the first occurrence of the substring str2 in the string str1.
*/

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	char	*c;
	int		i;
	int		j;

	i = -1;
	c = (char *)str1;
	if (*str2 == '\0')
		return (c);
	while (c[++i] != '\0')
	{
		j = 0;
		while (str1[i + j] == str2[j])
		{
			if (str2[j + 1] == '\0')
				return (&c[i]);
			++j;
		}
	}
	return (NULL);
}
