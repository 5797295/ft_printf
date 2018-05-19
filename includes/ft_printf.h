/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 19:15:04 by jukim             #+#    #+#             */
/*   Updated: 2018/05/18 22:59:14 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_yee
{
	va_list ap;
	char	*s;
	char	c;
	int		n;
	char	*minimum1;
	int		minimum2;
	int		minus;
	char	*w;
	int		wl;
	int		i;
	int		width;
	int		plus;
	int		zero;
	void	*v;
}				t_yee;

void	ft_printf(const char * restrict format, ...);

# endif
