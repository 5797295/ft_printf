/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:41:36 by jukim             #+#    #+#             */
/*   Updated: 2018/03/11 19:09:25 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns an array of “fresh”
** strings (all ending with ’\0’, including the array itself) obtained
** by spliting s using the character c as a delimiter.
** If the allocation fails the function returns NULL.
**
** Example: ft_strsplit("*hello*fellow***students*", ’*’) returns
** the array ["hello", "fellow", "students"].
*/

#include "libft.h"

static void	ft_fill(char **r, char *s, char c)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			++i;
			++len;
		}
		if (s[i - 1] != c)
		{
			r[j] = ft_strsub(s, i - len, len);
			j++;
		}
	}
}

static int	ft_check_char(char const *s, char c)
{
	int flag;
	int cnt;
	int i;

	i = 0;
	cnt = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 0;
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			cnt++;
		}
		i++;
	}
	return (cnt);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**r;
	int		i;

	if (!s)
		return (NULL);
	i = ft_check_char(s, c);
	if (!(r = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	r[i] = NULL;
	ft_fill(r, (char*)s, c);
	return (r);
}
