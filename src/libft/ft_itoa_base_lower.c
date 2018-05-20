/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 21:44:02 by jukim             #+#    #+#             */
/*   Updated: 2018/05/19 17:28:53 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long nb, int base)
{
	int	i;

	i = 1;
	while (nb >= base)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base_lower(unsigned long long n, int base)
{
	char				*s;
	unsigned long long	nb;
	int					len;

	nb = n;
	len = ft_intlen(nb, base);
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	while (len >= 0)
	{
		nb = n % base;
		if (nb >= 10)
			s[--len] = nb - 10 + 'a';
		else
			s[--len] = nb + '0';
		n = (unsigned long long)(n / base);
	}
	return (s);
}
