/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 19:08:50 by jukim             #+#    #+#             */
/*   Updated: 2018/05/16 22:40:47 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_printf(const char * restrict format, ...)
{
	t_yee	*p;
	int i;
	int j;

	p = malloc(sizeof(t_yee));
	va_start(p->ap, format);
	i = -1;
	while (format[++i] != '\0' && (j = -1))
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
			{
				i++;
				p->s = va_arg(p->ap, char *);
				while (p->s[++j] != '\0')
					write(1, &p->s[j], 1);
			}
			else if (format[i] == 'd' || (format[i] == '+' && format[i + 1] == 'd'))
			{
				i++;
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
			}
			else if (format[i] == 'p')
			{
				i++;
				p->v = va_arg(p->ap, void *);
				p->s = ft_itoa_base((unsigned long long)p->v, 16);
				while (p->s[++j] != '\0')
					write(1, &p->s[j], 1);
				free(p->s);
			}
		}
		write(1, &format[i], 1);
	}
	va_end(p->ap);
	free(p);
}
