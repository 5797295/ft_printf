/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:53:00 by jukim             #+#    #+#             */
/*   Updated: 2018/03/10 21:01:02 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** memory comparison
*/

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	const unsigned char *p1;
	const unsigned char *p2;

	p1 = str1;
	p2 = str2;
	while (len--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		else
		{
			p1++;
			p2++;
		}
	}
	return (0);
}
