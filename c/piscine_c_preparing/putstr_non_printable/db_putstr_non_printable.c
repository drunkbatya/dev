/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drunkbatya <drunkbatya.js@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:05:38 by drunkbaty         #+#    #+#             */
/*   Updated: 2022/01/10 13:58:04 by drunkbaty        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	db_putchar(char c)
{
	write(1, &c, 1);
}

int	db_is_printable(char c)
{
	if (c >= 0x00 && c <= 0x1F)
		return (0);
	if (c > 0x7E)
		return (0);
	return (1);
}

void	db_puthex_simple(char c)
{
	int	num;
	int	sym;
	int	offset;

	offset = 10;
	num = c / 16;
	sym = c % 15;
	db_putchar('\\');
	db_putchar(num + '0');
	if (sym < 10)
		db_putchar(sym + '0');
	else
		db_putchar(sym - offset + 'a');
}

void	db_putstr_non_printable(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (db_is_printable(str[count]))
			db_putchar(str[count]);
		else
			db_puthex_simple(str[count]);
		count++;
	}
}
