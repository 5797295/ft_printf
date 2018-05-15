/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:14:54 by jukim             #+#    #+#             */
/*   Updated: 2018/03/11 19:07:24 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** converts the initial portion of the string pointed to by str
** to int representation.
*/

#include "libft.h"

int						ft_atoi(const char *str)
{
	unsigned long long	i;
	unsigned long long	j;
	unsigned long long	k;

	i = 0;
	j = 0;
	k = 1;
	while (*str && (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' ||
				str[i] == '\v' || str[i] == ' ' || str[i] == '\f'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			k = -1;
		i++;
	}
	while (*str && str[i] >= '0' && str[i] <= '9')
	{
		j = (j * 10) + (str[i] - '0');
		i++;
	}
	if (i > 19 || j >= 9223372036854775808ULL)
		return (k == 1 ? -1 : 0);
	return (j * k);
}
