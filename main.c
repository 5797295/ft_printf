/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:52:31 by jukim             #+#    #+#             */
/*   Updated: 2018/05/22 00:48:46 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int		main()
{
//	char *s = "123";

//	printf("P - %%s: %12s	%%p: %p	%%c: %c %c\n", s, &s, 'a', 65);
//	ft_printf("F - %%s: %12s	%%p: %p	%%c: %c %c\n", s, &s, 'a', 65);
//	printf("%10s\n%10d\n", "abc", 123);
//	printf("%-5s\n", "123456");
//	int ret1;
//	int ret2;
//	ret1 = printf("%c", L'à');
//	ft_printf("%c", L'à');
//	ret2 = printf("%c", L'a');
//	ft_printf("F - %i %#X as\n", ret1, 123);
//	ft_printf("F - %i %#X as\n", ret1, 123);
//	ft_printf("F - %i %#X as\n", ret2, 123);
	printf("P - %10s %0.3s\n", "987654321", "12345678");
	ft_printf("F - %10s %0.3s\n", "987654321", "12345678");
//	ret1 = printf("%s\n", "abc");
//	printf("%d\n", ret1);
//	ft_printf("%C\n", L'à');
//	printf("%C\n", L'à');
	return (0);
}
