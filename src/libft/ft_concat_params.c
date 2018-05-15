/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:44:17 by jukim             #+#    #+#             */
/*   Updated: 2018/03/11 20:43:07 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** print each parameter on a new line.
*/

#include "libft.h"

char	*ft_concat_params(int argc, char **argv)
{
	char	*rc;
	int		i;
	int		l;
	int		k;
	size_t	j;

	i = -1;
	l = 0;
	k = 0;
	while (++i < argc)
		l += ft_strlen(argv[i]) + 1;
	rc = (char*)malloc(sizeof(char) * l);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (++j < ft_strlen(argv[i]))
			rc[j + k] = argv[i][j];
		rc[j + k] = '\n';
		k += j + 1;
	}
	rc[k - 1] = '\0';
	return (rc);
}
