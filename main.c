/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:52:31 by jukim             #+#    #+#             */
/*   Updated: 2018/05/19 20:01:08 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{
//	char *s = "123";

//	printf("P - %%s: %12s	%%p: %p	%%c: %c %c\n", s, &s, 'a', 65);
//	ft_printf("F - %%s: %12s	%%p: %p	%%c: %c %c\n", s, &s, 'a', 65);
//	printf("%10s\n%10d\n", "abc", 123);
//	printf("%-5s\n", "123456");
	int ret1;
	int ret2;
	ret1 = printf("P - %i %#X as\n", 123, 123);
	ret2 = ft_printf("F - %i %#X as\n", 123, 123);
	printf("p: %d f: %d\n", ret1, ret2);
	return (0);
}
