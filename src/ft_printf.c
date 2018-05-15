/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 19:08:50 by jukim             #+#    #+#             */
/*   Updated: 2018/05/15 16:46:05 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(const char * restrict format, ...)
{
	t_yee	*p;
	int i = -1;
	int j = -1;

	p = malloc(sizeof(t_yee));
	va_start(p->ap, format);
	while (format[++i] != '\0')
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
		}
		write(1, &format[i], 1);
	}
	va_end(p->ap);
	free(p);
}
