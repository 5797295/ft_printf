/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 19:08:50 by jukim             #+#    #+#             */
/*   Updated: 2018/05/18 00:13:58 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		low_c(t_yee *p, int i)
{
	p->c = va_arg(p->ap, int);
	write(1, &p->c, 1);
	return (i);
}

int		low_p(t_yee *p, int i, int j)
{
	p->v = va_arg(p->ap, void *);
	p->s = ft_itoa_base((unsigned long long)p->v, 16);
	while (p->s[++j] != '\0')
		write(1, &p->s[j], 1);
	free(p->s);
	return (i);
}

int		low_d_and_plus(t_yee *p, const char *restrict format, int i, int j)
{
	p->n = va_arg(p->ap, int);
	if (format[i - 1] == '+')
	{
		i++;
		p->n > 0 ? write(1, "+", 1) : 0;
	}
	p->s = ft_itoa(p->n);
	while (p->s[++j] != '\0')
		write(1, &p->s[j], 1);
	free(p->s);
	return (i);
}

int		low_s(t_yee *p, int i, int j)
{
	p->s = va_arg(p->ap, char *);
	while (p->s[++j] != '\0')
		write(1, &p->s[j], 1);
	return (i);
}

int		init(t_yee *p, const char *restrict format, int i, int n)
{
	while (ft_isdigit(format[i]) == 1)
	{
		n++;
		i++;
	}
	if (format[i] == 's')
		i = low_s(p, ++i, -1);
	else if (format[i] == 'd' || (format[i] == '+' && format[i + 1] == 'd'))
		i =low_d_and_plus(p, format, ++i, -1);
	else if (format[i] == 'p')
		i = low_p(p, ++i, -1);
	else if (format[i] == '%')
	{
		write(1, "%", 1);
		i++;
	}
	else if (format[i] == 'c')
		i = low_c(p, ++i);
	return (i);
}

void	ft_printf(const char *restrict format, ...)
{
	t_yee	*p;
	int		i;

	p = malloc(sizeof(t_yee));
	va_start(p->ap, format);
	i = -1;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			if (fotmat[i + 1] == '-')

			i = init(p, format, ++i, 0);
		}
		write(1, &format[i], 1);
	}
	va_end(p->ap);
	free(p);
}
