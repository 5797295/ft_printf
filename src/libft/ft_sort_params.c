/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:50:02 by jukim             #+#    #+#             */
/*   Updated: 2018/03/11 20:44:36 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** display arguments sorted by ASCII order in a single line all together.
*/

#include "libft.h"

char		*ft_sort_params(int argc, char **argv)
{
	int		i;
	int		a;
	char	*x;

	i = 1;
	while (i < (argc - 1))
	{
		a = i + 1;
		while (a < argc)
		{
			if (ft_strcmp(argv[i], argv[a]) > 0)
			{
				x = argv[i];
				argv[i] = argv[a];
				argv[a] = x;
			}
			a++;
		}
		i++;
	}
	i = 0;
	while (++i < argc)
		ft_putstr(argv[i]);
	return (0);
}
