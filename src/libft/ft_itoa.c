/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 20:45:46 by jukim             #+#    #+#             */
/*   Updated: 2018/03/10 22:39:57 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocate (with malloc(3)) and returns a “fresh” string ending
** with ’\0’ representing the integer n given as argument.
** Negative numbers must be supported. If the allocation fails,
** the function returns NULL.
*/

#include "libft.h"

static int	ft_intlen(long nb)
{
	int	i;

	i = 1;
	nb < 0 ? ++i : 0;
	nb < 0 ? nb *= -1 : 0;
	while (nb > 9)
	{
		++i;
		nb /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*s;
	long	nb;
	int		len;

	nb = (long)n;
	len = ft_intlen(nb);
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	nb < 0 ? s[0] = '-' : 0;
	nb < 0 ? nb *= -1 : 0;
	while (nb > 9)
	{
		s[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	s[--len] = nb + '0';
	return (s);
}
