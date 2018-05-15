/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:44:44 by jukim             #+#    #+#             */
/*   Updated: 2018/03/11 20:50:27 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int *rc;
	int i;

	if (min >= max)
		return (0);
	rc = (int*)malloc(sizeof(int) * (max - min));
	i = min;
	while (i < max)
	{
		rc[i - min] = i;
		i++;
	}
	return (rc);
}
