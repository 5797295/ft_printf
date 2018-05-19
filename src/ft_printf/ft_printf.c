/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 19:08:50 by jukim             #+#    #+#             */
/*   Updated: 2018/05/18 23:25:52 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		width(t_yee *p, const char *restrict format, int i, int n)
{
	p->wl = -1;
	n = i;
	while (ft_isdigit(format[n]) == 1)
	{
		if (n == i && format[n] == '0' && p->minus != 1)
		{
			p->zero = 0;
			n++;
		}
		else
			n++;
	}
	p->width = n - i;
	p->w = (char*)malloc(sizeof(char) * (p->width + 1));
	while (i < n)
	{
		p->w[++p->wl] = format[i];
		i++;
	}
	p->w[++p->wl] = '\0';
	p->width = ft_atoi(p->w);
	free(p->w);
	return (i);
}

int		low_c(t_yee *p, int i, int j)
{
	p->c = va_arg(p->ap, int);
	if (p->minus == 1 && p->width > 1)
	{
		write(1, &p->c, 1);
		while (p->width > 1 && ++j < p->width - 1)
			write(1, p->zero == 1 ? " " : "0" , 1);
	}
	else if (p->minus != 1 && p->width > 1)
	{
		while (p->width > 1 && ++j < p->width - 1)
			write(1, p->zero == 1 ? " " : "0", 1);
		write(1, &p->c, 1);
	}
	else
		write(1, &p->c, 1);
	return (i);
}

int		low_p(t_yee *p, int i, int j, int n)
{
	p->v = va_arg(p->ap, void *);
	p->s = ft_itoa_base((unsigned long long)p->v, 16);
	n = ft_strlen(p->s);
	if (p->minus == 1 && p->width > 1)
	{
		write(1, p->s, n);
		while (p->width > n && ++j < p->width - n)
			write(1, p->zero == 1 ? " " : "0", 1);
	}
	else if (p->minus != 1 && p->width > 1)
	{
		while (p->width > n && ++j < p->width - n)
			write(1, p->zero == 1 ? " " : "0", 1);
		write(1, p->s, n);
	}
	else
		write(1, p->s, n);
	free(p->s);
	return (i);
}

int		low_d_and_plus(t_yee *p, int i, int j, int n)
{
	p->n = va_arg(p->ap, int);

	p->s = ft_itoa(p->n);
	n = ft_strlen(p->s);
	if (p->minus == 1 && p->width > 1)
	{
		if (p->plus == 1)
		{
			p->n > 0 ? write(1, "+", 1) : 0;
			p->width--;
		}
		write(1, p->s, n);
		while (p->width > n && ++j < p->width - n)
			write(1, p->zero == 1 ? " " : "0", 1);
	}
	else if (p->minus != 1 && p->width > 1)
	{
		p->plus == 1 ? p->width-- : 0;
		if (p->plus == 1 && p->zero == 0)
			p->n > 0 ? write(1, "+", 1) : 0;
		while (p->width > n && ++j < p->width - n)
			write(1, p->zero == 1 ? " " : "0", 1);
		if (p->plus == 1 && p->zero == 1)
			p->n > 0 ? write(1, "+", 1) : 0;
		write(1, p->s, n);
	}
	else
		write(1, p->s, n);
	free(p->s);
	return (i);
}

int		low_s(t_yee *p, int i, int j, int n)
{
	p->s = va_arg(p->ap, char *);
	n = ft_strlen(p->s);
	if (p->minus == 1 && p->width > 1)
	{
		write(1, p->s, n);
		while (p->width > n && ++j < p->width - n)
			write(1, p->zero == 1 ? " " : "0", 1);
	}
	else if (p->minus != 1 && p->width > 1)
	{
		while (p->width > n && ++j < p->width - n)
			write(1, p->zero == 1 ? " " : "0", 1);
		write(1, p->s, n);
	}
	else
		write(1, p->s, n);
	return (i);
}

int		init(t_yee *p, const char *restrict format, int i)
{
	if (format[i] == 's')
		i = low_s(p, ++i, -1, -1);
	else if (format[i] == 'd' || (format[i] == '+' && format[i + 1] == 'd'))
		i = low_d_and_plus(p, ++i, -1, -1);
	else if (format[i] == 'p')
		i = low_p(p, ++i, -1, -1);
	else if (format[i] == '%')
	{
		write(1, "%", 1);
		i++;
	}
	else if (format[i] == 'c')
		i = low_c(p, ++i, -1);
	return (i);
}

void	init_values(t_yee *p)
{
	p->plus = 0;
	p->minus = 0;
	p->zero = 1;
}

void	ft_printf(const char *restrict format, ...)
{
	t_yee	*p;
	int i;

	p = malloc(sizeof(t_yee));
	va_start(p->ap, format);
	i = -1;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			init_values(p);
			while (format[i + 1] == '+' || format[i + 1] == '-')
			{
				format[i + 1] == '+' ? p->plus = 1 : 0;
				format[i + 1] == '-' ? p->minus = 1 : 0;
				i++;
			}
			if (ft_isdigit(format[i + 1]) == 1)
				i = init(p, format, (width(p, format, ++i, 0)));
			else
				i = init(p, format, ++i);
		}
		write(1, &format[i], 1);
	}
	va_end(p->ap);
	free(p);
}
