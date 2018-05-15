/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:08:44 by jukim             #+#    #+#             */
/*   Updated: 2018/03/11 19:02:11 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** lexicographically compare the null-terminated strings s1 and s2.
*/

#include "libft.h"

int					ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int				i;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (s1[i] && s1[i] == s2[i])
		++i;
	return (s1[i] - s2[i]);
}
