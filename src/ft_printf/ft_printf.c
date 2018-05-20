/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 19:08:50 by jukim             #+#    #+#             */
/*   Updated: 2018/05/19 20:07:18 by jukim            ###   ########.fr       */
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
		p->byte += write(1, &p->c, 1);
		while (p->width > 1 && ++j < p->width - 1)
			p->byte += write(1, p->zero == 1 ? " " : "0" , 1);
	}
	else if (p->minus != 1 && p->width > 1)
	{
		while (p->width > 1 && ++j < p->width - 1)
			p->byte += write(1, p->zero == 1 ? " " : "0", 1);
		p->byte += write(1, &p->c, 1);
	}
	else
		p->byte += write(1, &p->c, 1);
	return (i);
}

int		low_p(t_yee *p, int i, int j, int n)
{
	p->v = va_arg(p->ap, void *);
	p->s = ft_itoa_base((unsigned long long)p->v, 16);
	n = ft_strlen(p->s);
	if (p->minus == 1 && p->width > 1)
	{
		p->byte += write(1, p->s, n);
		while (p->width > n && ++j < p->width - n)
			p->byte += write(1, p->zero == 1 ? " " : "0", 1);
	}
	else if (p->minus != 1 && p->width > 1)
	{
		while (p->width > n && ++j < p->width - n)
			p->byte += write(1, p->zero == 1 ? " " : "0", 1);
		p->byte += write(1, p->s, n);
	}
	else
		p->byte += write(1, p->s, n);
	free(p->s);
	return (i);
}

int		upper_lower_x_and_o(t_yee *p, int i, int j, int n)
{
	p->n = va_arg(p->ap, int);
	p->x == 'x' ? (p->s = ft_itoa_base_lower(p->n, 16)) : 0;
	p->x == 'X' ? (p->s = ft_itoa_base_upper(p->n, 16)) : 0;
	p->x == 'o' ? (p->s = ft_itoa_base_lower(p->n, 8)) : 0;
	n = ft_strlen(p->s);
	if (p->minus == 1 && p->width > 1)
	{
		p->byte += write(1, p->s, n);
		while (p->width > n && ++j < p->width - n)
			p->byte += write(1, p->zero == 1 ? " " : "0", 1);
	}
	else if (p->minus != 1 && p->width > 1)
	{
		while (p->width > n && ++j < p->width - n)
			p->byte += write(1, p->zero == 1 ? " " : "0", 1);
		p->byte += write(1, p->s, n);
	}
	else
		p->byte += write(1, p->s, n);
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
			p->n > 0 ? p->byte += write(1, "+", 1) : 0;
			p->width--;
		}
		p->byte += write(1, p->s, n);
		while (p->width > n && ++j < p->width - n)
			p->byte += write(1, p->zero == 1 ? " " : "0", 1);
	}
	else if (p->minus != 1 && p->width > 1)
	{
		p->plus == 1 ? p->width-- : 0;
		if (p->plus == 1 && p->zero == 0)
			p->n > 0 ? p->byte += write(1, "+", 1) : 0;
		while (p->width > n && ++j < p->width - n)
			p->byte += write(1, p->zero == 1 ? " " : "0", 1);
		if (p->plus == 1 && p->zero == 1)
			p->n > 0 ? p->byte += write(1, "+", 1) : 0;
		p->byte += write(1, p->s, n);
	}
	else
		p->byte += write(1, p->s, n);
	free(p->s);
	return (i);
}

int		low_s(t_yee *p, int i, int j, int n)
{
	p->s = va_arg(p->ap, char *);
	n = ft_strlen(p->s);
	if (p->minus == 1 && p->width > 1)
	{
		p->byte += write(1, p->s, n);
		while (p->width > n && ++j < p->width - n)
			p->byte += write(1, p->zero == 1 ? " " : "0", 1);
	}
	else if (p->minus != 1 && p->width > 1)
	{
		while (p->width > n && ++j < p->width - n)
			p->byte += write(1, p->zero == 1 ? " " : "0", 1);
		p->byte += write(1, p->s, n);
	}
	else
		p->byte += write(1, p->s, n);
	return (i);
}

int		init(t_yee *p, const char *restrict format, int i)
{
	if (format[i] == 's')
		i = low_s(p, ++i, -1, -1);
	else if (format[i] == 'd' || (format[i] == '+' && format[i + 1] == 'd')
			|| format[i] == 'i' || (format[i] == '+' && format[i + 1] == 'i'))
		i = low_d_and_plus(p, ++i, -1, -1);
	else if (format[i] == 'p')
		i = low_p(p, ++i, -1, -1);
	else if (format[i] == 'x' || format[i] == 'X' || format[i] == 'o')
	{
		p->x = format[i];
		i = upper_lower_x_and_o(p, ++i, -1, -1);
	}
	else if (format[i] == '%')
	{
		p->byte += write(1, "%", 1);
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

int		hash(t_yee *p, const char *restrict format, int i)
{
	if (format[i + 2] == 'o')
		p->byte += write(1, "0", 1);
	else if (format[i + 2] == 'x')
		p->byte += write(1, "0x", 2);
	else if (format[i + 2] == 'X')
		p->byte += write(1, "0X", 2);
	return (i);
}

int		ft_printf(const char *restrict format, ...)
{
	t_yee	*p;
	int i;

	p = malloc(sizeof(t_yee));
	va_start(p->ap, format);
	p->byte = 0;
	i = -1;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			init_values(p);
			while (format[i + 1] == '+' || format[i + 1] == '-'
					|| format[i + 1] == '#')
			{
				if (format[i + 1] == '+')
					p->plus = 1;
				else if (format[i + 1] == '-')
					p->minus = 1;
				else if(format[i + 1] == '#')
					i = hash(p, format, i);
				i++;
			}
			if (ft_isdigit(format[i + 1]) == 1)
				i = init(p, format, (width(p, format, ++i, 0)));
			else
				i = init(p, format, ++i);
		}
		p->byte += write(1, &format[i], 1);
	}
	va_end(p->ap);
	free(p);
	return (p->byte);
}
