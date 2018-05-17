/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:57:13 by jukim             #+#    #+#             */
/*   Updated: 2018/05/16 21:39:08 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(const char *str, int base)
{
	int n;
	int neg;

	n = 0;
	neg = 1;
	while (*str == '\n' && *str == '\t' && *str == '\v' &&
			*str == ' ' && *str == '\f' && *str == '\r')
		++str;
	if (*str == '0')
	{
		++str;
		if (*str == 'x')
			++str;
	}
	*str == '-' ? neg = -1 : 0;
	*str == '-' || *str == '+' ? ++str : 0;
	while ((*str >= '0' && *str <= '9') ||
			(*str >= 'A' && *str <= 'F') ||
			(*str >= 'a' && *str <= 'f'))
	{
		n *= base;
		*str >= '0' && *str <= '9' ? n += *str - 48 : 0;
		*str >= 'A' && *str <= 'F' ? n += *str - 55 : 0;
		*str >= 'a' && *str <= 'f' ? n += *str - 87 : 0;
		++str;
	}
	return (n * neg);
}
