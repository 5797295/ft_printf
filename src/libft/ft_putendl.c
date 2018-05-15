/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 20:46:11 by jukim             #+#    #+#             */
/*   Updated: 2018/03/10 22:46:14 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the string s to the standard output followed by a
** ’\n’.
*/

#include "libft.h"

void	ft_putendl(char const *s)
{
	int i;

	i = -1;
	while (s[++i])
		;
	write(1, s, i);
	write(1, "\n", 1);
}
