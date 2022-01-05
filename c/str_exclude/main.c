/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:15:17 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/05 19:28:58 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "str_exclude.h"

void	db_putchar(char c)
{
	write(1, &c, 1);
}

void	db_putstr(char str[])
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		db_putchar(str[count++]);
}

int	main(void)
{
	char	str1[50] = "I love code\0";
	char	str2[3] = "oe\0";

	db_putstr("Original str: ");
	db_putstr(str1);
	db_putstr("\nExclude: ");
	db_putstr(str2);
	db_strexcl(str1, str2);
	db_putstr("\nModified str: ");
	db_putstr(str1);
	db_putstr("\n");
}
