/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 21:44:02 by jukim             #+#    #+#             */
/*   Updated: 2018/05/16 22:50:08 by jukim            ###   ########.fr       */
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

char		*ft_itoa_base(unsigned long long n, int base)
{
	char				*s;
	unsigned long long	nb;
	int					len;

	nb = n;
	len = ft_intlen(nb, base) + 2;
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	s[0] = '0';
	s[1] = 'x';
	while (len > 1)
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
/*char	*ft_itoa_base(int n, int base)
{
	char	*s;
	long	nb;
	int		len;

	len = 1;
	nb = n < 0 ? -(long)n : n;
	nb < 0 ? ++len : 0;
	while (nb >= base)
	{
		nb /= base;
		++len;
	}
	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	n < 0 ? *s = '-' : 0;
	nb = n < 0 ? -(long)n : n;
	while (nb >= base)
	{
		s[--len] = nb % base < 10 ? (nb % base) + 48 : (nb % base) + 55;
		nb /= base;
	}
	s[--len] = nb % base < 10 ? (nb % base) + 48 : (nb % base) + 55;
	return (s);
}*/
